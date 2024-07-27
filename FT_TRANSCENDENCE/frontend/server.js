// Import necessary modules
const express = require("express");
const path = require("path");
const https = require("https");
const fs = require("fs");

// Create an instance of an Express application
const app = express();

// Use express.static middleware to serve static files from the "frontend" directory
app.use(express.static(path.resolve("frontend")));

// Set up a route handler for GET requests made to any path (/*)
app.get("/*", (req, res) => {
    res.sendFile(path.resolve("frontend", "index.html"));
});

// Error handling
app.use((err, req, res, next) => {
    console.error(err.stack);
    res.status(500).send('Something broke!');
});

// Read the key and certificate files
const privateKey = fs.readFileSync(path.resolve("server.key"), "utf8");
const certificate = fs.readFileSync(path.resolve("server.cert"), "utf8");

// Create HTTPS server options
const httpsOptions = {
    key: privateKey,
    cert: certificate
};

// Create an HTTPS server with the Express app and the options
const httpsServer = https.createServer(httpsOptions, app);

// Start the HTTPS server
httpsServer.listen(process.env.PORT || 5500, () => console.log("HTTPS server running on 5500..."));