import { verify } from './Verifytoken.js';

console.log("Otherprofile.js loaded")

verify();

window.addEventListener('beforeunload', function (e) {
	fetch('https://10.13.250.44:8000/api/logout/', {
		method: 'GET',
		headers: {
			'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
		},
	})
});

let url = new URL(window.location.href);
let params = new URLSearchParams(url.search);
let username = params.get('username');

fetch('https://10.13.250.44:8000/api/user/' + username, {
	method: 'GET',
	headers: {
		'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
	},
})
	.then(response => response.json())
	.then(data => {
		// Sélectionnez les éléments HTML
		let usernameElement = document.getElementById('username');
		let emailElement = document.getElementById('email');
		let profilePhotoElement = document.getElementById('profilePhoto');

		// Définissez le contenu des éléments HTML
		usernameElement.textContent = data.username;
		emailElement.textContent = data.email;
		profilePhotoElement.src = 'https://10.13.250.44:8000/' + data.profile_photo;
	})
	/* .catch(error => console.error('Erreur:', error)); */
