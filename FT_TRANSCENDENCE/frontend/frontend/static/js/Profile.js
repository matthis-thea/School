import { navigateTo } from './index.js';
import { verify } from './Verifytoken.js';

console.log('Profile JS loaded');

verify();


window.addEventListener('beforeunload', function (e) {
	fetch('https://10.13.250.44:8000/api/logout/', {
		method: 'GET',
		headers: {
			'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
		},
	})
});

//-----------------------UPDATE PROFILE DATA-----------------------

const ProfileForm = document.querySelector('#ProfileForm');

ProfileForm.addEventListener('submit', async (event) => {
    // Prevent the default form submission
    event.preventDefault();

    // Get the username and password values
    const profilePhotoInput = document.querySelector('#profilePhotoInput');
    const username = document.querySelector('#id_username').value;
    const email = document.querySelector('#id_email').value;

    // Create a new FormData object
    const formData = new FormData();

    // Append the username, email, and profile photo to the FormData object
    formData.append('username', username);
    formData.append('email', email);
    if (profilePhotoInput.files[0]) {
        formData.append('profile_photo', profilePhotoInput.files[0]);
    }

    const response = await fetch('https://10.13.250.44:8000/api/update/', {
        method: 'PUT',
        headers: {
            'Authorization': 'Bearer ' + localStorage.getItem('accessToken'),
        },
        body: formData,
    });

    if (response.ok) {
        navigateTo('/');
    } else {
        fieldError(response);
    }
});

//-----------------------LOAD PROFILE DATA-----------------------

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

        // Ajouter l'image à l'élément parent
        document.getElementById('profilePhoto').appendChild(img);

        // Définir les valeurs des inputs sur les données renvoyées par le serveur
        document.getElementById('id_username').value = data.username;
        document.getElementById('id_email').value = data.email;

        // Obtenir l'image et l'input à partir de leurs IDs
        let imgInput = document.getElementById('profilePhoto');
        let input = document.getElementById('profilePhotoInput');

        // Utiliser la réponse du serveur comme source de l'image
        imgInput.src = 'https://10.13.250.44:8000' + data.profile_photo;

        // Ajouter un écouteur d'événement sur l'image pour déclencher l'input file quand on clique sur l'image
        imgInput.addEventListener('click', function () {
            input.click();
        });

        // Ajouter un écouteur d'événement sur l'input pour mettre à jour l'image quand un fichier est sélectionné
        input.addEventListener('change', function (e) {
            const file = e.target.files[0];
            if (file) {
                const reader = new FileReader();
                reader.onload = function (e) {
                    imgInput.src = e.target.result;
                };
                reader.readAsDataURL(file);
            }
        });

    })
    /* .catch(error => console.error('Erreur:', error)); */

//-----------------------LOAD RATIO DATA-----------------------

fetch('https://10.13.250.44:8000/api/user_game_win/', {
    method: 'GET',
    headers: {
        'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
    },
})
    .then(response => response.json())
    .then(data => {
        // Sélectionner les éléments HTML
        const victoryElement = document.getElementById('win');
        const defeatElement = document.getElementById('losses');
        const ratioElement = document.getElementById('ratio');

        // Mettre à jour les valeurs
        victoryElement.textContent = data.wins;
        defeatElement.textContent = data.losses;

        // Calculer et mettre à jour le ratio
        const totalGames = data.wins + data.losses;
        const ratio = totalGames > 0 ? Math.round((data.wins / totalGames) * 100) : 0;
        ratioElement.textContent = ratio;
    })
    /* .catch(error => console.error('Erreur:', error)); */

//-----------------------LOAD MATCH HISTORY DATA-----------------------

fetch('https://10.13.250.44:8000/api/user_game_stats/', {
    method: 'GET',
    headers: {
        'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
    },
})
    .then(response => response.json())
    .then(data => {
        /* console.log(data); */
        const cards = document.querySelectorAll('.container .row .col-md.bg-white.rounded-3.py-5');
        const matchHistoryContainer = cards[2]; // La troisième carte est à l'index 2

        if (matchHistoryContainer) {
            // Réinitialiser le conteneur et ajouter le titre
            matchHistoryContainer.innerHTML = '<h1 class="Montserrat fw-bold text-center">HISTORY</h1>';
            // Créer un nouveau conteneur pour les détails du match
            const matchDetailsContainer = document.createElement('div');
            matchDetailsContainer.className = 'match-details';
            matchHistoryContainer.appendChild(matchDetailsContainer);

            // Fonction pour afficher les données d'historique des matchs
            function renderMatchHistory(page) {
                matchDetailsContainer.innerHTML = '';

                const match = data[page - 1];
                matchDetailsContainer.innerHTML = `
                    <div class="d-flex justify-content-center align-items-center flex-column mb-3">
                        <div class="d-flex justify-content-center align-items-center">
                            <p id="player1" class="Montserrat fw-semibold text-center">${match.player_one}</p>
                            <p id="player1Score" class="Montserrat fw-bold text-center ms-1 me-3">${match.score_one}</p>
                            <p id="player2" class="Montserrat fw-semibold text-center">${match.player_two}</p>
                            <p id="player2Score" class="Montserrat fw-bold text-center ms-1 ">${match.score_two}</p>
                        </div>
                        <div class="d-flex justify-content-center align-items-center">
                            <p id="date" class="Montserrat fw-bold text-center ms-1 fs-1">${new Date(match.created_at).toLocaleDateString()}</p>
                        </div>
                    </div>
                `;
            }

            // Rendu initial
            let currentPage = 1;
            renderMatchHistory(currentPage);

            // Ajouter le conteneur de pagination si ce n'est pas déjà fait
            if (data.length > 1) {
                const totalPages = data.length;

                const paginationContainer = document.createElement('nav');
                paginationContainer.setAttribute('aria-label', 'Page navigation');
                paginationContainer.innerHTML = '<ul class="pagination justify-content-center"></ul>';
                matchHistoryContainer.appendChild(paginationContainer);

                const paginationUl = paginationContainer.firstElementChild;

                const prevPageItem = document.createElement('li');
                prevPageItem.className = 'page-item';
                prevPageItem.innerHTML = '<a class="page-link" href="#" aria-label="Previous"><span aria-hidden="true">&laquo;</span></a>';
                prevPageItem.addEventListener('click', (e) => {
                    e.preventDefault();
                    if (currentPage > 1) {
                        currentPage--;
                        renderMatchHistory(currentPage);
                        updatePagination();
                    }
                });
                paginationUl.appendChild(prevPageItem);

                for (let i = 1; i <= totalPages; i++) {
                    const pageItem = document.createElement('li');
                    pageItem.className = 'page-item' + (i === currentPage ? ' active' : '');
                    pageItem.innerHTML = `<a class="page-link" href="#">${i}</a>`;
                    pageItem.addEventListener('click', (e) => {
                        e.preventDefault();
                        currentPage = i;
                        renderMatchHistory(currentPage);
                        updatePagination();
                    });
                    paginationUl.appendChild(pageItem);
                }

                const nextPageItem = document.createElement('li');
                nextPageItem.className = 'page-item';
                nextPageItem.innerHTML = '<a class="page-link" href="#" aria-label="Next"><span aria-hidden="true">&raquo;</span></a>';
                nextPageItem.addEventListener('click', (e) => {
                    e.preventDefault();
                    if (currentPage < totalPages) {
                        currentPage++;
                        renderMatchHistory(currentPage);
                        updatePagination();
                    }
                });
                paginationUl.appendChild(nextPageItem);

                function updatePagination() {
                    document.querySelectorAll('.page-item').forEach((item, index) => {
                        item.classList.toggle('active', index === currentPage);
                    });
                }
            }

            // Ajouter du CSS pour modifier la couleur
            const style = document.createElement('style');
            style.innerHTML = `
                .pagination .page-link {
                    color: #1abc9c; /* Change la couleur du texte */
                }
                .pagination .page-item.active .page-link {
                    background-color: #1abc9c; /* Change la couleur de fond pour l'élément actif */
                    border-color: #1abc9c; /* Change la couleur de la bordure pour l'élément actif */
                }
            `;
            document.head.appendChild(style);
        }
    })
   /*  .catch(error => console.error('Erreur:', error)); */

//-----------------------SHOW ERRORS-----------------------

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
