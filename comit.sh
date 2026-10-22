#!/bin/bash

# Affiche un message demandant le commentaire du commit
echo "Entrez votre message de commit (ou appuyez sur Entrée pour un message par défaut) :"
read commit_msg

# Si aucun message n'est entré, on met un message par défaut avec la date/heure
if [ -z "$commit_msg" ]; then
    commit_msg="Mise à jour automatique : $(date '+%Y-%m-%d %H:%M:%S')"
fi

echo "--- Étape 1 : Ajout des fichiers (git add) ---"
git add .

echo "--- Étape 2 : Validation (git commit) ---"
git commit -m "$commit_msg"

echo "--- Étape 3 : Envoi sur GitHub (git push) ---"
git push

echo "--- Opération terminée avec succès ! ---"