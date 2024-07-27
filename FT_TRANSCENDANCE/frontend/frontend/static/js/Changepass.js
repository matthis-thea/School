import { navigateTo } from './index.js';
import { verify } from './Verifytoken.js';

console.log('Register JS loaded');

verify();


window.addEventListener('beforeunload', function (e) {
	fetch('https://10.13.250.44:8000/api/logout/', {
		method: 'GET',
		headers: {
			'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
		},
	})
});


const passForm = document.querySelector('#passForm');

// Add an event listener to the form
passForm.addEventListener('submit', async (event) => {
	// Prevent the default form submission
	event.preventDefault();
	// Remove all existing error messages
	const existingErrorMessages = document.querySelectorAll('.error-message');
	existingErrorMessages.forEach((errorMessage) => {
		errorMessage.remove();
	});

	// Get the username and password values
	const old_password = document.querySelector('#id_old_password').value;
	const password1 = document.querySelector('#id_password1').value;
	const password2 = document.querySelector('#id_password2').value;

	const response = await fetch('https://10.13.250.44:8000/api/update_password/', {
		method: 'PUT', // Change 'POST' to 'PUT'
		headers: {
			'Authorization': 'Bearer ' + localStorage.getItem('accessToken'),
			'Content-Type': 'application/json' // Add this line
		},
		body: JSON.stringify({old_password, password1, password2}),
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
            errorMessage.textContent = errorData[field].password || errorData[field]; // Utilisez errorData[field].password si disponible, sinon errorData[field]
            errorMessage.classList.add('error-message');
            errorMessage.style.color = 'red'; // Appliquez le style pour le texte en rouge
            inputField.parentNode.insertBefore(errorMessage, inputField.nextSibling);
        }
    }
}