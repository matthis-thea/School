FROM alpine:latest

# Mise à jour et installation des paquets nécessaires
RUN apk update &&\
    apk upgrade &&\
    apk add nodejs npm openssl

# Création du répertoire de travail
RUN mkdir /frontend; \
    chmod +rwx /frontend
WORKDIR /frontend

# Copie des fichiers du projet
COPY . .

# Installation des dépendances npm
RUN npm install

# Génération de la clé privée et du certificat auto-signé
RUN openssl req -x509 -newkey rsa:4096 -keyout /frontend/server.key -out /frontend/server.cert -days 365 -nodes -subj "/C=FR/ST=GrandEst/L=Mulhouse/O=42/CN=pong.fr"

# Expose port 5500 for the application
EXPOSE 5500

# Commande pour démarrer l'application
CMD ["npm", "start"]