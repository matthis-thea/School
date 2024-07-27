import { navigateTo } from './index.js';

console.log('Register JS loaded');

const registerForm = document.querySelector('#registerForm');

// Add an event listener to the form
registerForm.addEventListener('submit', async (event) => {
	// Prevent the default form submission
	event.preventDefault();
	// Remove all existing error messages
	const existingErrorMessages = document.querySelectorAll('.error-message');
	existingErrorMessages.forEach((errorMessage) => {
		errorMessage.remove();
	});

	// Get the username and password values
	const username = document.querySelector('#id_username').value;
	const email = document.querySelector('#id_email').value;
	const password1 = document.querySelector('#id_password1').value;
	const password2 = document.querySelector('#id_password2').value;

	const response = await fetch('https://10.13.250.44:8000/api/register/', {
		method: 'POST',
		headers: {
			'Content-Type': 'application/json',
		},
		body: JSON.stringify({username, email, password1, password2}),
	});

	if (response.ok) {
		// If the response is OK, redirect the user to the login page
		navigateTo('/');
	} else {
		fieldError(response);
	}
});

async function fieldError(response) {
	/* console.error('Error:', response.status, response.statusText); */
	const errorData = await response.json();
	/* console.error(errorData); */

	for (const field in errorData) {
		const inputField = document.querySelector(`#id_${field}`);
		if (inputField) {
			inputField.classList.add('error');
			const errorMessage = document.createElement('div');
			errorMessage.textContent = errorData[field];
			errorMessage.classList.add('error-message');
			inputField.parentNode.insertBefore(errorMessage, inputField.nextSibling);
		}
	}
}
