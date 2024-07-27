// Importing Login and SignUp views from the views directory
import Login from "./views/LoginView.js";
import SignUp from "./views/SignUpView.js";
import Play from "./views/PlayView.js";
import NotFound from "./views/404.js";
import Logout from "./views/LogoutView.js";
import Profile from "./views/ProfileView.js";
import Changepass from "./views/ChangepassView.js";
import InvitationQM from "./views/InvitationQMView.js";
import InvitationTM from "./views/InvitationTMView.js";
import Otherprofile from "./views/OtherprofileView.js";
import Quickmatch from "./views/QuickmatchView.js";

// The router function
const router = async () => {
	// Defines the routes for the application
	const routes = [
		{ path: '/', view: Login }, // Login view for the root path
		{ path: '/logout', view: Logout }, // Logout view for the '/logout' path
		{ path: '/signUp', view: SignUp }, // SignUp view for the '/signUp' path
		{ path: '/play', view: Play }, // Play view for the '/play' path
		{ path: '/profile', view: Profile }, // Profile view for the '/profile' path
		{ path: '/changepass', view: Changepass }, // Change password view for the '/changepass' path
		{ path: '/invitationQM', view: InvitationQM }, // Quick match view for the '/invitation' path
        { path: '/invitationTM', view: InvitationTM }, // Tournament match view for the '/invitation' path
		{ path: '/otherprofile', view: Otherprofile }, // Other profile view for the '/otherprofile' path
		{ path: '/quickmatch', view: Quickmatch }, // Quick match view for the '/quickmatch' path
		{ path: '/404', view: NotFound }, // 404 view for the '/404' path
		{ path: '*', view: NotFound }, // 404 view for any other path
	];

	// Get the JWT from localStorage
	const jwt = localStorage.getItem('accessToken');

	// Maps over the routes to find a match for the current path
	const potentialMatches = routes.map(route => {
		return {
			route: route,
			// Checks if the current path matches the route path
			isMatch: location.pathname === route.path
		};
	});

	// Finds the first route that matches the current path
	let match = potentialMatches.find(potentialMatch => potentialMatch.isMatch);

    // Si aucun match n'est trouvé, redirige vers la route par défaut (404)
    if (!match) {
        match = potentialMatches.find(potentialMatch => potentialMatch.route.path === '/play');
    }

	// If a JWT exists and the URL is the login or register page, redirect to the play page
	if (jwt && (location.pathname === '/' || location.pathname === '/signUp')) {
		match = potentialMatches.find(potentialMatch => potentialMatch.route.path === '/play');
	}
	// If a JWT doesn't exist and the URL is not the login or register page, redirect to the login page
	else if (!jwt && location.pathname !== '/' && location.pathname !== '/signUp') {
		match = potentialMatches.find(potentialMatch => potentialMatch.route.path === '/');
	}

	// Creates a new instance of the matched view
	const view = new match.route.view();

	// Replaces the content of the '#app' element with the HTML of the matched view
	document.querySelector('#app').innerHTML = await view.getHtml();

	// Émettre un événement personnalisé indiquant que la vue a changé
	const event = new CustomEvent('viewchange', { detail: { path: match.route.path } });
	window.dispatchEvent(event);
};

// Adds an event listener for the 'popstate' event to handle browser back/forward navigation
window.addEventListener('popstate', router);

// Adds an event listener for the 'DOMContentLoaded' event to start the router once the DOM is fully loaded
document.addEventListener('DOMContentLoaded', () => {
	document.body.addEventListener('click', e => {
		if (e.target.matches('[data-link]')) {
			e.preventDefault();
			navigateTo(e.target.href);
		}
	});
	router();
});

// Function to navigate to a given URL
export const navigateTo = url => {
	// Get the JWT from localStorage
	const jwt = localStorage.getItem('accessToken');

	// If a JWT exists and the URL is the login or register page, redirect to the play page
	if (jwt && (url.endsWith('/signUp') || url.endsWith('/'))) {
		url = '/play';
	}
	// If a JWT doesn't exist and the URL is not the login or register page, redirect to the login page
	else if (!jwt && url.endsWith('/play')){
		url = '/';
	}

	console.log("redirecting to: ", url);
	// Pushes the given URL to the browser history stack
	history.pushState(null, null, url);
	// Calls the router function to handle the new URL
	router();
};

