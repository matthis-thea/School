import { navigateTo } from './index.js';

console.log('Login JS loaded');

const form = document.getElementById('LoginForm');

const initialSubmitHandler = async function (event) {
	event.preventDefault();

	const username = document.querySelector('#id_username').value;
	const password = document.querySelector('#id_password').value;

	try {
		await login(username, password);

		if (document.querySelector('#id_2FA')) {
			form.removeEventListener('submit', initialSubmitHandler);

			form.addEventListener('submit', async function tokenSubmitHandler(event) {
				event.preventDefault();
				const code_otp = document.querySelector('#id_2FA').value;
				await verifyToken(username, password, code_otp);
			});
		}
	} catch (error) {
		/* console.error(error); */
	}
};

async function login(username, password) {
	try {
		const response = await fetch('https://10.13.250.44:8000/api/login/', {
			method: 'POST',
			headers: {
				'Content-Type': 'application/json',
			},
			body: JSON.stringify({ username, password }),
		});

		if (response.ok) {
			const element = document.getElementById('2FA');
			element.innerHTML = `
			<p>
			<label for="id_2FA">Token:</label>
			<input type="text" name="2FA" maxlength="30" required id="id_2FA">
			</p>
			`;
		} else {
			await handleFieldError(response);
		}
	} catch (error) {
		/* console.error('Login failed:', error); */
	}
}

async function verifyToken(username, password, code_otp) {
	try {
		const response = await fetch('https://10.13.250.44:8000/api/verification/', {
			method: 'POST',
			headers: {
				'Content-Type': 'application/json',
			},
			body: JSON.stringify({ username, password, code_otp }),
		});

		if (response.ok) {
			const data = await response.json();
			localStorage.setItem('accessToken', data.access_token);
			localStorage.setItem('refreshToken', data.refresh_token);
			navigateTo('/play');
		} else {
			await handleFieldError(response);
		}
	} catch (error) {
		/* console.error('Token verification failed:', error); */
	}
}

async function handleFieldError(response) {
	// Affiche le statut et le texte du statut dans la console
	/* console.error('Error:', response.status, response.statusText); */

	// Convertit le corps de la réponse en JSON
	const errorData = await response.json();

	// Affiche les données d'erreur JSON dans la console
	/* console.error(errorData); */

	// Sélectionne la div avec l'ID "LoginErrors"
	const loginErrorsDiv = document.getElementById('LoginErrors');

	// Vérifie si la div existe et si l'objet JSON contient un champ "detail"
	if (loginErrorsDiv && errorData.detail) {
		// Met à jour le contenu de la div avec le message d'erreur
		loginErrorsDiv.textContent = errorData.detail;
		loginErrorsDiv.classList.add('error-message');
	}
}


form.addEventListener('submit', initialSubmitHandler);
