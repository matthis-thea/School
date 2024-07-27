import { navigateTo } from './index.js';
import { verify } from './Verifytoken.js';

console.log('Invitation QM JS loaded');

verify();

let invitedFriends = []; // Array to store invited friends

createFriendList();


window.addEventListener('beforeunload', function (e) {
	fetch('https://10.13.250.44:8000/api/logout/', {
		method: 'GET',
		headers: {
			'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
		},
	})
});

// Function to create friend list
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

			data.friends.forEach(friend => {
				const listItem = document.createElement('li');
				listItem.className = 'list-group-item d-flex justify-content-between align-items-center Montserrat cursorPointer fw-bold';

				const usernameSpan = document.createElement('span');
				usernameSpan.textContent = friend.username;
				usernameSpan.className = 'usernameSpan';
				listItem.appendChild(usernameSpan);

				const inviteButton = document.createElement('button');
				inviteButton.type = 'button';
				inviteButton.className = 'btn btn-success invite-button';
				inviteButton.textContent = 'Invite';
				inviteButton.style = 'padding: 5px; padding-top: 0px; padding-bottom: 0px;';
				listItem.appendChild(inviteButton);

				friendList.appendChild(listItem);

				usernameSpan.addEventListener('click', function () {
					seeProfile(friend.username);
				});

				inviteButton.addEventListener('click', function (event) {
					event.preventDefault();
					inviteFriend(friend.username, inviteButton);
				});
			});
		})
		/* .catch(error => console.error('Error:', error)); */
}

// Function to invite a friend
async function inviteFriend(username, inviteButton) {
	if (invitedFriends.length >= 3) {
		// If already invited three friends, do nothing
		return;
	}

	if (invitedFriends.includes(username)) {
		// If already invited this friend, do nothing
		return;
	}

	try {
		// Add friend to invited list
		invitedFriends.push(username);

		// Update button state to loading
		inviteButton.innerHTML = `
            <div class="spinner-border" role="status">
                <span class="visually-hidden">Loading...</span>
            </div>
        `;
		inviteButton.disabled = true;

		// Check if three friends have been invited
		if (invitedFriends.length === 3) {
			// Call function to send invitations
			await sendInvitations();
		}
	} catch (error) {
		/* console.error('Error:', error); */
	}
}
// Function to send invitations
// Function to send invitations
async function sendInvitations() {
	try {
		// Destructure the first three invited usernames
		const [username_one, username_two, username_three] = invitedFriends;

		const response = await fetch('https://10.13.250.44:8000/api/send_invitation_tournaments/', {
			method: 'POST',
			headers: {
				'Content-Type': 'application/json',
				'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
			},
			body: JSON.stringify({ username_one, username_two, username_three }),	
		});

		if (response.ok) {
			// Handle success
			/* console.log('Invitations sent successfully.'); */
			// Clear invited friends list
			invitedFriends = [];
			// Replace inviteCard content with the new HTML
			const inviteCard = document.getElementById('inviteCard');
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
					<div class="row">
                        <div class="col-md-4 col-12">
                            <div id="prflPhotoOther3">
								<div class="spinner-border m-4" role="status">
                                    <span class="visually-hidden">Loading...</span>
                                </div>
							</div>
                        </div>
                        <div class="col-md-4 col-12 mt-4 Montserrat fw-bold text-center">
                            VS
                        </div>
                        <div class="col-md-4 col-12">
                            <div id="prflPhotoOther2">
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
		} else {
			const data = await response.json();
			// Handle error response
			/* console.error('Error:', data); */
		}
	} catch (error) {
		/* console.error('Error:', error); */
	} finally {
		// Reset button states if needed
		const inviteButtons = document.querySelectorAll('.invite-button');
		inviteButtons.forEach(button => {
			button.innerHTML = 'Invite';
			button.disabled = false;
		});
	}
}


// Function to see profile
function seeProfile(username) {
	navigateTo("/otherprofile?username=" + username);
}

// Function to remove all child nodes from a parent element
function removeAllChildNodes(parent) {
	while (parent.firstChild) {
		parent.removeChild(parent.firstChild);
	}
}
