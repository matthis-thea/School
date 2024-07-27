import { navigateTo } from './index.js';
import { verify } from './Verifytoken.js';

console.log('Play JS loaded');

verify();


window.addEventListener('beforeunload', function (e) {
	fetch('https://10.13.250.44:8000/api/logout/', {
		method: 'GET',
		headers: {
			'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
		},
	})
});

const quickCard = document.querySelector('#quickCard');

quickCard.addEventListener('click', async (event) => {
	navigateTo("/invitationQM")
});

const tournamentCard = document.querySelector('#tournamentCard');

tournamentCard.addEventListener('click', async (event) => {
	navigateTo("/invitationTM")
});

