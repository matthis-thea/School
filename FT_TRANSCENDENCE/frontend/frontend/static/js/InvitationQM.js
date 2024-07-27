import { navigateTo } from './index.js';
import { verify } from './Verifytoken.js';

console.log('Invitation JS loaded');

verify();

createFriendList();


window.addEventListener('beforeunload', function (e) {
	fetch('https://10.13.250.44:8000/api/logout/', {
		method: 'GET',
		headers: {
			'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
		},
	})
});

//FRIEND LIST
function createFriendList() {
	fetch('https://10.13.250.44:8000/api/friends_list/', {
		method: 'GET',
		headers: {
			'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
		},
	})
		.then(response => response.json())
		.then(data => {
			const friendList = document.getElementById('friendListMatch');
			removeAllChildNodes(friendList);
			friendList.innerHTML = '';

			data.friends.forEach(friend => {
				const listItem = document.createElement('li');
				listItem.className = 'list-group-item d-flex justify-content-between align-items-center Montserrat cursorPointer fw-bold';

				const usernameSpan = document.createElement('span');
				usernameSpan.textContent = friend.username;
				usernameSpan.className = 'usernameSpan';
				listItem.appendChild(usernameSpan);

				const inviteButton = document.createElement('button');
				inviteButton.type = 'button';
				inviteButton.className = 'btn btn-success';
				inviteButton.textContent = 'Invite';
				inviteButton.style = 'padding: 5px; padding-top: 0px; padding-bottom: 0px;';
				listItem.appendChild(inviteButton);

				friendList.appendChild(listItem);

				usernameSpan.addEventListener('click', function () {
					seeProfile(friend.username);
				});

				inviteButton.addEventListener('click', function (event) {
					event.preventDefault();
					inviteFriend(friend.username);
				});
			});
		})
		/* .catch(error => console.error('Error:', error)); */
}

//INVITE FRIEND
async function inviteFriend(username) {
	const inviteCard = document.getElementById('inviteCard');
	removeAllChildNodes(inviteCard);
	inviteCard.innerHTML = `
    <div class="container text-center mt-5">
        <div class="row">
            <div class="col-md-4 col-12">
                <div id="prflPhotoMe"></div>
            </div>
            <div class="col-md-4 col-12 mt-4 Montserrat fw-bold text-center">
                VS
            </div>
            <div class="col-md-4 col-12">
                <div id="prflPhotoOther">
					<div class="spinner-border m-4" role="status">
					<span class="visually-hidden">Loading...</span>
				</div>
                </div>
            </div>
        </div>
    </div>
`;
	//SEE PHOTO PROFILE
	fetch('https://10.13.250.44:8000/api/user', {
		method: 'GET',
		headers: {
			'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
		},
	})
		.then(response => response.json())
		.then(data => {
			// Créer une nouvelle balise img pour la photo de profil
			let img = document.createElement('img');
			img.className = 'rounded';
			img.width = 100;
			img.height = 100;
			img.alt = 'Photo de profil';

			document.getElementById('prflPhotoMe').appendChild(img);
			img.src = 'https://10.13.250.44:8000' + data.profile_photo; // Utilisez img.src au lieu de imgInput.src
		})
		/* .catch(error => console.error('Erreur:', error)); */

	//SEND INVITATION
	try {
		const response = await fetch('https://10.13.250.44:8000/api/send_invitation/', {
			method: 'POST',
			headers: {
				'Content-Type': 'application/json',
				'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
			},
			body: JSON.stringify({ username }),
		})
		if (response.ok) {
			// Invitation sent successfully
		} else {
			const data = await response.json();
			const toastHeader = document.querySelector("#liveToastInfo .Montserrat.fw-bold");
			toastHeader.textContent = data.detail; // Set the toast header to the error message
			var toastEl = document.querySelector('#liveToastInfo');
			var toast = new bootstrap.Toast(toastEl);
			toast.show(); // Show the toast
		}
	} catch (error) {
		/* console.error('Login failed:', error); */
	}
}
//SEE PROFILE
function seeProfile(username) {
	navigateTo("/otherprofile?username=" + username);
}

function removeAllChildNodes(parent) {
	while (parent.firstChild) {
		parent.removeChild(parent.firstChild);
	}
}