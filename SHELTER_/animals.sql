-- MySQL dump 10.13  Distrib 5.7.21, for macos10.13 (x86_64)
--
-- Host: localhost    Database: animals
-- ------------------------------------------------------
-- Server version	5.7.21

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `animal`
--

DROP TABLE IF EXISTS `animal`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `animal` (
  `cid` int(10) unsigned NOT NULL,
  `animalType` char(1) NOT NULL,
  `name` varchar(150) NOT NULL,
  `sex` char(1) NOT NULL,
  `breed` varchar(150) NOT NULL,
  `boxNumber` int(10) unsigned NOT NULL,
  `foundDate` date NOT NULL,
  `foundStreet` varchar(150) NOT NULL,
  `hasDisease` char(1) NOT NULL,
  `diseaseName` varchar(150) DEFAULT NULL,
  `colourHair` varchar(150) NOT NULL,
  `colourEye` varchar(150) NOT NULL,
  `hasHome` char(1) NOT NULL,
  PRIMARY KEY (`cid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `animal`
--

LOCK TABLES `animal` WRITE;
/*!40000 ALTER TABLE `animal` DISABLE KEYS */;
INSERT INTO `animal` VALUES (1,'D','Lisa','W','Liseu',23,'2014-12-01','Westmount','N',NULL,'brown','green','Y'),(2,'C','Demon','M','Bengal',0,'2014-12-11','Main','N',NULL,'white','blue','Y'),(3,'D','Morgan','M','Border Collie',43,'2015-01-04','Cannon','N',NULL,'black','black','N'),(4,'D','Merry','W','Akita',2,'2015-05-24','Abbey','N',NULL,'gray','green','Y'),(5,'D','Jerry','M','Pomeranian',7,'2015-06-06','Smith','N',NULL,'pink','green','Y'),(6,'C','Amy','W','Korat',1,'2015-08-15','Fermi','Y','FELV','brown','gray','N'),(7,'C','Howard','M','Manx',3,'2015-09-30','Orchart','N',NULL,'yellow','violet','N'),(8,'D','Penny','W','Mastiff',56,'2015-10-01','Gewert','N',NULL,'orange','blue','Y'),(9,'C','Sheldon','M','Somali',4,'2015-11-21','Curie','Y','FIV','white','green','N'),(10,'D','Atos','W','Spaniel',12,'2018-09-09','Main','N','','blue','red','N');
/*!40000 ALTER TABLE `animal` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-04-23 13:01:15
