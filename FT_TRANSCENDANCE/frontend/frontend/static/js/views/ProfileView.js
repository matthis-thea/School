import AbstractView from "./AbstractView.js";

export default class extends AbstractView {
	constructor() {
		super();
		this.setTitle("Profile");
	}

	async getHtml() {
		try {
			// Load profile.html
			const response = await fetch('static/html/profile.html');
			if (!response.ok) {
				throw new Error('Failed to load HTML file');
			}
			const htmlContent = await response.text();

			// Load menu.html
			const menuResponse = await fetch('static/html/menu.html');
			if (!menuResponse.ok) {
				throw new Error('Failed to load menu HTML file');
			}
			const menuHtmlContent = await menuResponse.text();

			// Append menu HTML to the main HTML content
			const finalHtmlContent = htmlContent + menuHtmlContent;

			// Clear JS div
			const jsDiv = document.querySelector('#JS');
			jsDiv.innerHTML = '';

			// Load Profile.js
			const script = document.createElement('script');
			script.type = 'module';
			script.src = `./static/js/Profile.js?${new Date().getTime()}`;
			jsDiv.appendChild(script);

			// Load Menu.js
			let script2 = document.createElement('script');
			script2.type = 'module';
			script2.src = './static/js/Menu.js' + '?' + new Date().getTime();
			jsDiv.appendChild(script2);

			return finalHtmlContent;
		} catch (error) {
			console.error('Error loading HTML file:', error);
			// Return an error message or a fallback version of the view
			return `<div>Error loading HTML file: ${error.message}</div>`;
		}
	}
}
