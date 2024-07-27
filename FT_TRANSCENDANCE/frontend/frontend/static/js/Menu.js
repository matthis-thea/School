import { navigateTo } from './index.js';

console.log('menu.js loaded');


window.addEventListener('beforeunload', function (e) {
	fetch('https://10.13.250.44:8000/api/logout/', {
		method: 'GET',
		headers: {
			'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
		},
	})
});

//----------------------------------------------WEB SOCKET INPUT----------------------------------------------
if (window.webSocketMenu) {
	/* console.log('WSMENU already initialized'); */
} else {
	window.webSocketMenu = true;

	fetch('https://10.13.250.44:8000/api/user', {
		method: 'GET',
		headers: {
			'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
		},
	})
		.then(response => response.json())
		.then(data => {
			const username = data.username;
			const socketMenu = new WebSocket(`wss://10.13.250.44:8001/ws/notifications/${username}/?token=` + localStorage.getItem('accessToken'));

			localStorage.setItem('socketMenu', socketMenu);

			socketMenu.onopen = function (event) {
				console.log('WS MENU OUVERTE', event);
			};

			socketMenu.onmessage = function (event) {
				const data = JSON.parse(event.data);
				/* console.log("Message WebSocket reçu:", data); // Ajout pour afficher le message */
			
				let toastElementId;
				if (data.confirmation) {
					toastElementId = 'liveToastConfirmation';
				} else if (data.information) {
					toastElementId = 'liveToastInfo';
				}
				if (toastElementId) {
					const message = data.confirmation || data.information;
					showToast(message, toastElementId);
				}
				else if (data['no-display']) {
					if (data['bool'] === '0') {
						localStorage.setItem('invitation_id', data['no-display']);
						localStorage.setItem('tournament', '0');
					}
					else if (data['bool'] === '450') {
						localStorage.setItem('invitation_id', data['no-display']);
						localStorage.setItem('tournament', '1');
					}
					else if (data.bool === '397') {
						navigateTo("/quickmatch?room=" + data['no-display']);
					}
				}
			};
			socketMenu.onclose = function (event) {
				console.log('WS MENU FERMEE', event);
			};

			socketMenu.onerror = function (error) {
				/* console.error('Erreur WebSocket', error); */
			};

			window.addEventListener('beforeunload', function () {
				if (socketMenu) {
					socketMenu.close();
					webSocketMenu = false;
					console.log('WS MENU FERMEE');
				}
			});
		})
		/* .catch(error => console.error('Erreur:', error)); */
}



//----------------------------------------------SHOW TOAST----------------------------------------------

function showToast(message, toastElementId) {
	const toastElement = document.getElementById(toastElementId);

	const toastHeader = toastElement.querySelector('.toast-header .me-auto');
	if (toastHeader) {
		toastHeader.textContent = message;
	}
	const toast = new bootstrap.Toast(toastElement);
	toast.show();
	createFriendList();
}

//----------------------------------------------INVITE TOAST-----------------------------------------


document.querySelector('#acceptToast').addEventListener('click', function () {
	const invitation_id = localStorage.getItem('invitation_id');
	const accepted = 'True';
	var tournament;
	
	if(localStorage.getItem('tournament') === '1')
		tournament = "_tournaments"
	else
		tournament = ""

	fetch('https://10.13.250.44:8000/api/response_invitation' + tournament + '/', {
		method: 'POST',
		headers: {
			'Content-Type': 'application/json',
			'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
		},
		body: JSON.stringify({ invitation_id, accepted }),
	})
		/* .catch(error => console.error('Error:', error)); */
});

document.querySelector('#declineToast').addEventListener('click', function () {
	const invitation_id = localStorage.getItem('no-display-info');
	const accepted = 'False';
	fetch('https://10.13.250.44:8000/api/response_invitation' + tournament + '/', {
		method: 'POST',
		headers: {
			'Content-Type': 'application/json',
			'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
		},
		body: JSON.stringify({ invitation_id, accepted }),
	});

	// Hide the toast
	var toastEl = document.getElementById('liveToastConfirmation');
	var toast = new bootstrap.Toast(toastEl);
	toast.hide();
});


//----------------------------------------------FRIENDS----------------------------------------------
createFriendList();

//FRIEND LIST
function updateFriendList() {
    createFriendList();
}

function createFriendList() {
    fetch('https://10.13.250.44:8000/api/friends_list/', {
        method: 'GET',
        headers: {
            'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
        },
    })
    .then(response => response.json())
    .then(data => {
        const friendList = document.getElementById('friendList');
        removeAllChildNodes(friendList);
        friendList.innerHTML = '';

        data.friends.forEach(friend => {
            const listItem = document.createElement('li');
            listItem.className = 'list-group-item d-flex justify-content-between align-items-center Montserrat cursorPointer fw-bold';

            const textContainer = document.createElement('div');
            textContainer.className = 'd-flex flex-grow-1 align-items-center';

            const usernameSpan = document.createElement('span');
            usernameSpan.textContent = friend.username;
            usernameSpan.className = 'usernameSpan';
            textContainer.appendChild(usernameSpan);

            const statusSpan = document.createElement('span');
            switch(friend.status) {
                case 1: // Connecté
                    statusSpan.className = 'badge rounded-pill text-bg-primary ms-auto me-2'; // ms-auto pushes the element to the right
                    statusSpan.textContent = 'Online';
                    break;
                case 0: // Non connecté
                    statusSpan.className = 'badge rounded-pill text-bg-secondary ms-auto me-2';
                    statusSpan.textContent = 'Offline';
                    break;
                case 2: // Ingame
                    statusSpan.className = 'badge rounded-pill text-bg-warning ms-auto me-2';
                    statusSpan.textContent = 'Ingame';
                    break;
                default:
                    statusSpan.className = 'badge rounded-pill text-bg-dark ms-auto me-2';
                    statusSpan.textContent = 'Inconnu';
            }
            textContainer.appendChild(statusSpan);
            listItem.appendChild(textContainer);

            const deleteButton = document.createElement('button');
            deleteButton.type = 'button';
            deleteButton.className = 'btn btn-danger deleteFriend';
            deleteButton.textContent = '-';
            deleteButton.style = 'padding: 5px; padding-top: 0px; padding-bottom: 0px;';
            listItem.appendChild(deleteButton);

            friendList.appendChild(listItem);

			usernameSpan.addEventListener('click', function () {
				seeProfile(friend.username);
			});

			deleteButton.addEventListener('click', function (event) {
				event.preventDefault();
				deleteFriend(friend.username);
			});
        });
    });
}

//DELETE FRIEND
function deleteFriend(username) {
	fetch('https://10.13.250.44:8000/api/remove_friends/', {
		method: 'POST',
		headers: {
			'Content-Type': 'application/json',
			'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
		},
		body: JSON.stringify({ username }),
	})
		.then(response => {
			if (!response.ok) {
				throw new Error('Network response was not ok');
			}
			return response.json();
		})
		.then(data => {
			createFriendList();
		})
		.catch(error => {
			/* console.error('Error:', error); */
		});
}

//ADD FRIEND
friendForm.addEventListener('submit', function (event) {
	event.preventDefault();

	const username = document.getElementById('friendInput').value;

	fetch('https://10.13.250.44:8000/api/friends_add/', {
		method: 'POST',
		headers: {
			'Content-Type': 'application/json',
			'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
		},
		body: JSON.stringify({ username }),
	})
		.then(response => {
			if (!response.ok) {
				throw new Error('Network response was not ok');
			}
			return response.json();
		})
		.then(data => {
			var toastEl = document.getElementById('liveToastInfo');
			var toastHeader = toastEl.querySelector('.toast-header .me-auto');
			if (toastHeader) {
				toastHeader.textContent = data.detail; // Use 'detail' field from the server response
			}
			var toast = new bootstrap.Toast(toastEl);
			toast.show();
			createFriendList();
		})
		.catch(error => {
			/* console.error('Error:', error); */
			var toastEl = document.getElementById('liveToastInfo');
			var toastHeader = toastEl.querySelector('.toast-header .me-auto');
			if (toastHeader) {
				toastHeader.textContent = "Friend request failed";
			}
			var toast = new bootstrap.Toast(toastEl);
			toast.show();
		});
});
//----------------------------------------------MENUS----------------------------------------------


//TRIGGER SIDEBAR
(function () {
	document.querySelector('.sidebar-toggle').addEventListener('click', function () {
		let myOffcanvas = document.getElementById('offcanvasWithBothOptions');
		let bsOffcanvas = new bootstrap.Offcanvas(myOffcanvas);
		updateFriendList();
		bsOffcanvas.show();
	});

	let toastTrigger = document.getElementById('liveToastBtn')
	let toastLiveExample = document.getElementById('liveToastInfo')

	if (toastTrigger) {
		let toastBootstrap = bootstrap.Toast.getOrCreateInstance(toastLiveExample)
		toastTrigger.addEventListener('click', () => {
			toastBootstrap.show()
		})
	}

	document.getElementById('profileDropdown').addEventListener('click', function () {
		let popItem = document.getElementById('popItem');
		if (popItem.classList.contains('visible')) {
			popItem.classList.remove('visible');
		} else {
			popItem.classList.add('visible');
		}
	});
})();


//LOAD PROFILE PHOTO
fetch('https://10.13.250.44:8000/api/user_picture', {
	method: 'GET',
	headers: {
		'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
	},
})
	.then(response => response.json())
	.then(data => {
		// Créer une nouvelle balise img
		let img = document.createElement('img');
		img.className = 'rounded fthover';
		img.width = 37;
		img.height = 37;
		img.alt = 'Photo de profil';
		img.style.marginTop = '0.73rem';
		img.style.marginLeft = '1.1rem';

		// Utiliser la réponse du serveur comme source de l'image
		img.src = 'https://10.13.250.44:8000' + data.profile_image_url;

		// Ajouter l'image à l'élément parent
		document.getElementById('prflPhoto').appendChild(img);
	})
	/* .catch(error => console.error('Erreur:', error)); */


function removeAllChildNodes(parent) {
	while (parent.firstChild) {
		parent.removeChild(parent.firstChild);
	}
}

// Flag pour détecter la navigation interne
let isInternalNavigation = false;

// Détecter les clics sur les liens et les formulaires
document.addEventListener('click', function(event) {
    if (event.target.tagName === 'A' || event.target.closest('form')) {
        isInternalNavigation = true;
    }
});

// Réinitialiser le flag après le chargement de la nouvelle page
window.addEventListener('beforeunload', function(event) {
    if (!isInternalNavigation) {
        // Déclencher l'appel API de déconnexion uniquement si la fenêtre se ferme
        fetch('https://10.13.250.44:8000/api/logout/', {
            method: 'GET',
            headers: {
                'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
            }
        });
    }
    isInternalNavigation = false;
});


// Function to see profile
function seeProfile(username) {
	navigateTo("/otherprofile?username=" + username);
}