import { navigateTo } from './index.js';

console.log('Logout JS loaded');
const socketMenu = localStorage.getItem('socketMenu');

/* socketMenu.close(); */
// Remove all entries

fetch('https://10.13.250.44:8000/api/logout/', {
    method: 'GET',
    headers: {
        'Authorization': 'Bearer ' + localStorage.getItem('accessToken')
    },
})

localStorage.clear();
navigateTo('/');
