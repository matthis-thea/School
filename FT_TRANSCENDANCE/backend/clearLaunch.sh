##!/bin/bash

# Arrêter l'exécution en cas d'erreur
set -e

# Creer l'environnement virtuel
python3 -m venv env

# Activer l'environnement virtuel
echo "Activating virtual environment..."
source env/bin/activate

# Installer les dépendances du projet
echo "Installing dependencies..."
pip install -r requirements.txt

# Appliquer les migrations de la base de données
echo "Applying database migrations..."
python3 manage.py makemigrations
python3 manage.py migrate

# Creer le certificat ssl
openssl req -x509 -nodes -out cert.crt -keyout key.key -subj "/C=FR/ST=GRANDEST/L=MULHOUSE/O=42/OU=42/CN=pong.fr/UID=tunsinge"

# Lancer le serveur Django
echo "Starting Django development server..."
python3 manage.py runserver_plus 0.0.0.0:8000 --cert-file cert.crt --key-file key.key
