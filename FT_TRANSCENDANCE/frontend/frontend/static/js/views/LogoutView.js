import AbstractView from "./AbstractView.js";

export default class extends AbstractView {
	constructor() {
		super();
		this.setTitle("Logout");
	}

	async getHtml() {
		try {
			const response = await fetch('static/html/logout.html'); // Assurez-vous de modifier l'URL en fonction de l'emplacement réel de votre fichier HTML
			if (!response.ok) {
				throw new Error('Failed to load HTML file');
			}
			//LOAD JS
			const jsDiv = document.querySelector('#JS');
			jsDiv.innerHTML = '';
			const script = document.createElement('script');
			script.type = 'module';
			script.src = `./static/js/Logout.js?${new Date().getTime()}`;
			document.querySelector('#JS').appendChild(script);

			const htmlContent = await response.text();
			return htmlContent;
		} catch (error) {
			console.error('Error loading HTML file:', error);
			// Retourner un message d'erreur ou une version de secours de la vue
			return `<div>Error loading HTML file: ${error.message}</div>`;
		}
	}
}
