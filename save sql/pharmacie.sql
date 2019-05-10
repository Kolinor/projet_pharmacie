-- phpMyAdmin SQL Dump
-- version 4.6.6deb5
-- https://www.phpmyadmin.net/
--
-- Client :  localhost:3306
-- Généré le :  Ven 10 Mai 2019 à 16:07
-- Version du serveur :  5.7.26-0ubuntu0.18.04.1
-- Version de PHP :  7.2.17-0ubuntu0.18.04.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `pharmacie`
--
CREATE DATABASE IF NOT EXISTS `pharmacie` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `pharmacie`;

-- --------------------------------------------------------

--
-- Structure de la table `Medicament`
--

CREATE TABLE `Medicament` (
  `ID_Medicament` int(20) NOT NULL,
  `Nom_Medicament` varchar(30) NOT NULL,
  `Hauteur` float NOT NULL,
  `Largeur` float NOT NULL,
  `Longueur` float NOT NULL,
  `Quantite_Restante` int(20) NOT NULL,
  `Code_Barre` int(50) NOT NULL,
  `Prix` int(20) NOT NULL,
  `Nombre_Unite_Vendu` int(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `Medicament`
--

INSERT INTO `Medicament` (`ID_Medicament`, `Nom_Medicament`, `Hauteur`, `Largeur`, `Longueur`, `Quantite_Restante`, `Code_Barre`, `Prix`, `Nombre_Unite_Vendu`) VALUES
(10, 'Doliprane', 2.3, 2, 2.55, 6, 4, 8, 645),
(22, 'Doliprane 1000', 12, 12, 12, 0, 12, 12, 0),
(25, 'Pansement x50', 10, 30, 4098, 6305, 654, 606, 0),
(26, 'Spasfon 500', 160, 80, 160, 0, 26, 1000000000, 0),
(29, 'Spasfon 1000', 100, 100, 100, 0, 100000, 100000, 0);

-- --------------------------------------------------------

--
-- Structure de la table `Ordonnance`
--

CREATE TABLE `Ordonnance` (
  `ID_Ordonnance` int(20) NOT NULL,
  `Etat` varchar(20) NOT NULL,
  `Numero_Caisse` int(3) NOT NULL,
  `Date_Saisie_Ordonnance` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `Ordonnance`
--

INSERT INTO `Ordonnance` (`ID_Ordonnance`, `Etat`, `Numero_Caisse`, `Date_Saisie_Ordonnance`) VALUES
(1, 'en attente', 2, '2019-05-10'),
(2, 'en attente', 1, '2019-05-10');

-- --------------------------------------------------------

--
-- Structure de la table `Ordonnance_Medicament_Association`
--

CREATE TABLE `Ordonnance_Medicament_Association` (
  `ID_Ordonnance` int(15) NOT NULL,
  `Nom_Medicament` varchar(30) NOT NULL,
  `Quantite_Demande` int(15) NOT NULL,
  `Quantite_Delivree` int(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `Ordonnance_Medicament_Association`
--

INSERT INTO `Ordonnance_Medicament_Association` (`ID_Ordonnance`, `Nom_Medicament`, `Quantite_Demande`, `Quantite_Delivree`) VALUES
(27, 'Doliprane', 3, 0),
(27, 'Pansement x50', 5, 0),
(27, 'Spasfon 1000', 1, 0),
(26, 'Doliprane', 5, 0);

-- --------------------------------------------------------

--
-- Structure de la table `ParametreAutomate`
--

CREATE TABLE `ParametreAutomate` (
  `Cle` varchar(20) NOT NULL,
  `Value` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `ParametreAutomate`
--

INSERT INTO `ParametreAutomate` (`Cle`, `Value`) VALUES
('Verin 1', '3s66xs'),
('bite', 'bite'),
('TEST', '123456'),
('langlace', 'gremont');

--
-- Index pour les tables exportées
--

--
-- Index pour la table `Medicament`
--
ALTER TABLE `Medicament`
  ADD PRIMARY KEY (`ID_Medicament`),
  ADD UNIQUE KEY `Code_Barre` (`Code_Barre`),
  ADD UNIQUE KEY `Nom_Medicament` (`Nom_Medicament`);

--
-- Index pour la table `Ordonnance`
--
ALTER TABLE `Ordonnance`
  ADD PRIMARY KEY (`ID_Ordonnance`),
  ADD UNIQUE KEY `ID_Ordonnance` (`ID_Ordonnance`);

--
-- Index pour la table `Ordonnance_Medicament_Association`
--
ALTER TABLE `Ordonnance_Medicament_Association`
  ADD KEY `ID_Medicament` (`Nom_Medicament`),
  ADD KEY `ID_Ordonnance` (`ID_Ordonnance`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `Medicament`
--
ALTER TABLE `Medicament`
  MODIFY `ID_Medicament` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=30;
--
-- AUTO_INCREMENT pour la table `Ordonnance`
--
ALTER TABLE `Ordonnance`
  MODIFY `ID_Ordonnance` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `Ordonnance_Medicament_Association`
--
ALTER TABLE `Ordonnance_Medicament_Association`
  ADD CONSTRAINT `Ordonnance_Medicament_Association_ibfk_2` FOREIGN KEY (`ID_Ordonnance`) REFERENCES `Ordonnance` (`ID_Ordonnance`),
  ADD CONSTRAINT `Ordonnance_Medicament_Association_ibfk_3` FOREIGN KEY (`Nom_Medicament`) REFERENCES `Medicament` (`Nom_Medicament`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
