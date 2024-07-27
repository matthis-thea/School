import AbstractView from "./AbstractView.js";

export default class extends AbstractView {
	constructor() {
		super();
		this.setTitle("404");
	}

	async getHtml() {
		try {
			const response = await fetch('static/html/404.html'); // Assurez-vous de modifier l'URL en fonction de l'emplacement réel de votre fichier HTML
			if (!response.ok) {
				throw new Error('Failed to load HTML file');
			}
			//LOAD JS
			const jsDiv = document.querySelector('#JS');
			jsDiv.innerHTML = '';

			const htmlContent = await response.text();
			return htmlContent;
		} catch (error) {
			console.error('Error loading HTML file:', error);
			// Retourner un message d'erreur ou une version de secours de la vue
			return `<div>Error loading HTML file: ${error.message}</div>`;
		}
	}
}
