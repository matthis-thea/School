import { navigateTo } from './index.js';

// Function to navigate to a given URL
export function verify() {
	const token = localStorage.getItem('accessToken');
	fetch('https://10.13.250.44:8000/api/verify-token/', {
		method: 'POST',
		headers: {
			'Content-Type': 'application/json',
			'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
		},
		body: JSON.stringify({ token }),
	})
	.then(response => response.json())
	.then(data => {
		if (data.code === 'token_not_valid') {
			navigateTo('/logout');
		}
	})
	/* .catch(error => console.error('Error:', error)); */
}
