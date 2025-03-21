# cub3D

## Description

Ce projet est inspiré de Wolfenstein 3D, le premier FPS jamais créé. Il consiste à réaliser une représentation graphique réaliste d'un labyrinthe en 3D à la première personne en utilisant la technique du raycasting.

## Fonctionnalités

- Mouvements du joueur : déplacements avant, arrière, latéraux et rotation de la caméra
- Affichage réaliste de textures sur les murs
- Minicarte pour faciliter la navigation
- Possibilité de collecter des objets dans le labyrinthe

## Prérequis

- Système d'exploitation : Linux ou macOS
- MiniLibX installée sur votre système pour le rendu graphique

## Installation

1. Cloner le dépôt :

```
git clone https://github.com/6lence/cub3D.git
cd cub3D
```

2. Compiler le projet :

```
make
```

## Utilisation

- Lancer le programme :

```
./cub3D <chemin/vers/map.cub>
```

Exemple avec une carte disponible dans le dossier `maps` :

```
./cub3D maps/exemple.cub
```

- Contrôles du jeu :

  - `W` : Avancer
  - `S` : Reculer
  - `A` : Aller à gauche
  - `D` : Aller à droite
  - Flèche gauche : Rotation caméra gauche
  - Flèche droite : Rotation caméra droite
  - `ESC` : Quitter

## Ressources Utiles

- [Documentation MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
- [Tutoriel sur le Raycasting](https://lodev.org/cgtutor/raycasting.html)

## Licence

Projet sous licence MIT. Voir le fichier [LICENSE](LICENSE).
