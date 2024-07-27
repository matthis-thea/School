import { navigateTo } from './index.js';
import { verify } from './Verifytoken.js';

console.log('QuickMatch JS loaded');

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
let room = params.get('room');
let socketGame = new WebSocket(`wss://10.13.250.44:8001/ws/pong/` + room + `/?token=` + localStorage.getItem('accessToken'));
let photoEnnemy;
let photoMe;
let skipcount = 0;
let falsecount = 0;
let closeWS = 0;

//----------------------------------------------WEB SOCKET INPUT----------------------------------------------

async function initializeWebSocket() {
	if (window.webSocketGame) {
		/* console.log('WS GAME already initialized'); */
		return;
	} else {

		window.webSocketGame = true;

		socketGame.onopen = function (event) {
			console.log('WS GAME OUVERTE', event);
			setTimeout(function () {
				fetchEnemyProfile(room);
			}, generateRandomNumber(0, 500));
		};

		socketGame.onmessage = async function (event) { // Mark this function as async
			let data = JSON.parse(event.data);
			/* console.log(data); */
			if (data.ready === 'True') {
				let cardInvited = document.getElementById('cardInvited');
				let cardGame = document.getElementById('cardGame');

				cardInvited.classList.remove('d-block');
				cardInvited.classList.add('d-none');

				cardGame.classList.remove('d-none');
				cardGame.classList.add('d-block');
			} else if (data.ready === 'False' && falsecount === 0) {
				falsecount = 1;
				let cardGame = document.getElementById('cardGame');
				// Vider le contenu actuel de cardGame
				cardGame.innerHTML = '';

				// Créer une nouvelle carte Bootstrap avec le message d'erreur
				let errorCard = document.createElement('div');
				errorCard.className = 'card text-center bg-white';
				errorCard.style = 'margin-top: 50vh !important';
				let cardBody = document.createElement('div');
				cardBody.className = 'card-body';
				let errorMessage = document.createElement('p');
				if (data.message) { // Vérifiez si data.message existe avant de l'utiliser
					errorMessage.textContent = data.message;
				}

				// Assembler la carte et l'ajouter à cardGame
				cardBody.appendChild(errorMessage);
				errorCard.appendChild(cardBody);
				cardGame.appendChild(errorCard);

				// Rediriger après 1 secondes
				setTimeout(function () {
					navigateTo('/profile');
				}, 1000);
			}
			else if (data.status === 'Skip' && skipcount === 0) {
				skipcount = 1;
				navigateTo("/quickmatch?room=" + data.final_code);
			} else {
				
				try {
					if (data.ball_position) {
						updateBallPosition(data.ball_position);
					}
					// Vérifie si le message contient la position du paddle
					if (data.paddle_position) {
						updateRightPaddlePosition(data.paddle_position);
					}
					if (data.scores_me !== undefined && data.scores_ennemies !== undefined) {
						displayScore(data.scores_me, data.scores_ennemies);
					}
				} catch (e) {
					/* console.error('Erreur de parsing du BALL POSITION WS:', e); */
				}
			}
		};
	};

	socketGame.onclose = function (event) {
		window.webSocketGame = false; // Réinitialiser la variable
		console.log('WS GAME FERMEE');
	};

	socketGame.onerror = function (error) {
		/* console.error('Erreur WebSocket', error); */
	};

	// Écouter les changements de vue pour fermer la WebSocket
	window.addEventListener('viewchange', function () {
		if (socketGame && closeWS === 0) {
			closeWS = 1;
			socketGame.close();
			console.log('WS GAME FERMEE -> REDIRECTION');
		}
	});

}

//----------------------------------------------MEDIAS----------------------------------------------

// SEE PHOTO PROFILE
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
		img.src = 'https://10.13.250.44:8000' + data.profile_photo;

		photoMe = 'https://10.13.250.44:8000' + data.profile_photo;

		const prflPhotoMeInGame = document.getElementById('prflPhotoMeInGame');
		prflPhotoMeInGame.src = photoMe;

		// Remplacer l'icône de chargement par l'image
		let profileContainer = document.getElementById('prflPhotoMe');
		profileContainer.innerHTML = ''; // Supprimer l'icône de chargement
		profileContainer.appendChild(img);
	})
	/* .catch(error => console.error('Erreur:', error)); */

// SEE ENEMY PHOTO PROFILE
function fetchEnemyProfile(room) {
	fetch('https://10.13.250.44:8000/api/user_detail_game/', {
		method: 'POST',
		headers: {
			'Content-Type': 'application/json',
			'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
		},
		body: JSON.stringify({ room }),
	})
		.then(response => response.json())
		.then(data => {
			let img = document.createElement('img');
			img.className = 'rounded';
			img.width = 100;
			img.height = 100;
			img.alt = 'Photo de profil';
			img.src = 'https://10.13.250.44:8000/media/' + data.profile_photo;

			photoEnnemy = 'https://10.13.250.44:8000/media/' + data.profile_photo;
			const prflPhotoMeEnnemyGame = document.getElementById('prflPhotoMeEnnemyGame');
			prflPhotoMeEnnemyGame.src = photoEnnemy;

			let profileContainer = document.getElementById('prflPhotoOther');
			profileContainer.innerHTML = '';
			profileContainer.appendChild(img);
		})
		/* .catch(error => console.error('Erreur:', error)); */
}

//----------------------------------------------INGAME MEDIAS----------------------------------------------
const prflPhotoMeInGame = document.getElementById('prflPhotoMeInGame');
const prflPhotoMeEnnemyGame = document.getElementById('prflPhotoMeEnnemyGame');
prflPhotoMeInGame.src = photoMe;
prflPhotoMeEnnemyGame.src = photoEnnemy;

//----------------------------------SEND TO WS----------------------------------
const leftPaddle = document.getElementById('leftPaddle');
const rightPaddle = document.getElementById('rightPaddle');
const ball = document.getElementById('ball');
const pongTable = document.querySelector('.pong-table');

let paddle_position = 0; // Position initiale du paddle (milieu)
const paddleSpeed = 2; // Vitesse de déplacement du paddle

document.addEventListener('keydown', function (event) {
	if (event.key === 'ArrowUp') {
		paddle_position = Math.max(paddle_position - paddleSpeed, 0);
	} else if (event.key === 'ArrowDown') {
		paddle_position = Math.min(paddle_position + paddleSpeed, 80); // Limiter la position à 80
	}
	updatePaddlePosition();
});

leftPaddle.addEventListener('touchmove', function (event) {
	event.preventDefault(); // Empêche le comportement par défaut (défilement de la page)
	let touch = event.touches[0]; // Récupère le premier toucher de l'événement
	let newPosition = touch.pageY / window.innerHeight * 100; // Calcule la nouvelle position en pourcentage de la hauteur de la fenêtre
	paddle_position = Math.max(Math.min(newPosition, 80), 0); // Limite la position entre 0 et 80
	updatePaddlePosition();
}, false);

function updatePaddlePosition() {
	const maxPosition = pongTable.clientHeight - leftPaddle.clientHeight;
	const newPosition = (paddle_position / 80) * maxPosition; // Ajuster la position en fonction de la limite de 80

	leftPaddle.style.top = newPosition + 'px';

	// Ajuster la hauteur du paddle pour qu'il s'étende de 80 à 100
	if (paddle_position === 80) {
		const paddleHeight = (20 / 100) * maxPosition; // 20% de la hauteur du terrain de jeu
		const newPaddleHeight = maxPosition - newPosition;
		leftPaddle.style.height = Math.max(paddleHeight, newPaddleHeight) + 'px';
	} else {
		leftPaddle.style.height = (20 / 100) * maxPosition + 'px'; // Réinitialiser la hauteur du paddle
	}

	// Envoyer la position du paddle au serveur via le WebSocket
	sendPaddlePosition(paddle_position);
}

function updateRightPaddlePosition(position) {
	const maxPosition = pongTable.clientHeight - rightPaddle.clientHeight;
	const newPosition = (position / 80) * maxPosition; // Adjust the position based on the 80 limit

	rightPaddle.style.top = newPosition + 'px';

	// Adjust the height of the paddle to extend from 80 to 100
	if (position === 80) {
		const paddleHeight = (20 / 100) * maxPosition; // 20% of the game field height
		const newPaddleHeight = maxPosition - newPosition;
		rightPaddle.style.height = Math.max(paddleHeight, newPaddleHeight) + 'px';
	} else {
		rightPaddle.style.height = (20 / 100) * maxPosition + 'px'; // Reset the paddle height
	}
}
function updateBallPosition(ballPosition) {
	const maxX = pongTable.clientWidth - ball.clientWidth;
	const maxY = pongTable.clientHeight - ball.clientHeight;

	const ballLeft = (ballPosition[0] / 100) * maxX;
	const ballTop = (ballPosition[1] / 100) * maxY;

	ball.style.left = ballLeft + 'px';
	ball.style.top = ballTop + 'px';
}

function sendPaddlePosition(position) {
	if (socketGame.readyState === WebSocket.OPEN) {
		// Limiter la position du paddle à 80 avant de l'envoyer
		const message = {
			type: 'paddle_position',
			data: { paddle_position: position }
		};
		socketGame.send(JSON.stringify(message));
	}
}

function displayScore(myScore, enemyScore) {
	const myScoreDiv = document.getElementById('scoreMe');
	const enemyScoreDiv = document.getElementById('scoreEnnemy');

	// Crée et ajoute le score du joueur
	myScoreDiv.textContent = myScore;

	// Crée et ajoute le score de l'ennemi
	enemyScoreDiv.textContent = enemyScore;
}

function generateRandomNumber(min, max) {
	return Math.floor(Math.random() * (max - min + 1)) + min;
}

function sleep(ms) {
	return new Promise(resolve => setTimeout(resolve, ms));
}


initializeWebSocket();