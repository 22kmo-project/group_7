-- MySQL dump 10.13  Distrib 8.0.30, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: group_7
-- ------------------------------------------------------
-- Server version	8.0.29

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `account`
--

DROP TABLE IF EXISTS `account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `account` (
  `id_account` int NOT NULL AUTO_INCREMENT,
  `id_client` int DEFAULT NULL,
  `balance` float DEFAULT NULL,
  PRIMARY KEY (`id_account`),
  KEY `client_account_idx` (`id_client`),
  CONSTRAINT `client_account` FOREIGN KEY (`id_client`) REFERENCES `client` (`id_client`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account`
--

LOCK TABLES `account` WRITE;
/*!40000 ALTER TABLE `account` DISABLE KEYS */;
INSERT INTO `account` VALUES (1,7,7000),(2,6,200),(4,6,400),(5,10,6000),(6,10,450),(7,11,70);
/*!40000 ALTER TABLE `account` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `card`
--

DROP TABLE IF EXISTS `card`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `card` (
  `id_card` int NOT NULL AUTO_INCREMENT,
  `id_client` int DEFAULT NULL,
  `id_account` int DEFAULT NULL,
  `pin` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id_card`),
  KEY `account_card_idx` (`id_account`),
  KEY `client_card_idx` (`id_client`),
  CONSTRAINT `account_card` FOREIGN KEY (`id_account`) REFERENCES `account` (`id_account`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `client_card` FOREIGN KEY (`id_client`) REFERENCES `client` (`id_client`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `card`
--

LOCK TABLES `card` WRITE;
/*!40000 ALTER TABLE `card` DISABLE KEYS */;
INSERT INTO `card` VALUES (3,11,7,'$2a$10$tl4ZK/fQhRAsTsgdctD9a.IBOPVRFx53RY22RsC.ah499ZZKP6KFe'),(5,6,2,'$2a$10$9zqMsYojy0tOC3WoA.ViuuXmM9U6H9eh3e87pJf/lIfolfw47FVbi'),(6,10,6,'$2a$10$aHCrVV5NXUR6kHIOoQbj2ed02zCHPA4JlyXrKHqSmscNuPDkCR41.'),(7,11,7,'$2a$10$F5G/Pho./Ek/1QhJgJSgaudwxFqQPmlwyKU.dyRxcyDq.Wr7XLIFC'),(8,6,4,'$2a$10$uLl4OAhMFEeMfadGg81vAe/ZNOkvkrIUT.RBVYKFSrItpRs5NDSZy'),(11,6,4,'$2a$10$ehRGq3YlM.T2YJv3etUAtuwBWXw2iO0W421Mnm3Na/6imX0EBK2Vy'),(12,7,1,'$2a$10$QC6Xd8xGt9uX6.rCh.1fO..iSchtkRr33UCIQNy2aTCiseLRmqtUe'),(13,10,5,'$2a$10$oy8K/pk5Ja.cOoMfzz0qmOtwL5JlgY031nH3gC5nyLo.wIR8GuLNO');
/*!40000 ALTER TABLE `card` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `client`
--

DROP TABLE IF EXISTS `client`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `client` (
  `id_client` int NOT NULL AUTO_INCREMENT,
  `fname` varchar(50) DEFAULT NULL,
  `lname` varchar(50) DEFAULT NULL,
  `addr_street` varchar(50) DEFAULT NULL,
  `addr_municipality` varchar(50) DEFAULT NULL,
  `phone_num` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`id_client`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `client`
--

LOCK TABLES `client` WRITE;
/*!40000 ALTER TABLE `client` DISABLE KEYS */;
INSERT INTO `client` VALUES (6,'Assu','Asiakas','Kuja 455','Oulu','040994422'),(7,'Kolmas','Kökkönen','Osoite 55','93600 Kuusamo','0401234567'),(10,'Testi','Asiakas','Testitie 5A7','90120 Oulu','0400112233'),(11,'Riki','Koira','Kuusitie 6','90120 Oulu','0401122333');
/*!40000 ALTER TABLE `client` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transaction`
--

DROP TABLE IF EXISTS `transaction`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transaction` (
  `id_transaction` int NOT NULL AUTO_INCREMENT,
  `id_account` int DEFAULT NULL,
  `id_card` int DEFAULT NULL,
  `transaction_date` date DEFAULT NULL,
  `transaction` varchar(45) DEFAULT NULL,
  `amount` float DEFAULT NULL,
  PRIMARY KEY (`id_transaction`),
  KEY `account_transaction_idx` (`id_account`),
  KEY `card_transaction_idx` (`id_card`),
  CONSTRAINT `account_transaction` FOREIGN KEY (`id_account`) REFERENCES `account` (`id_account`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `card_transaction` FOREIGN KEY (`id_card`) REFERENCES `card` (`id_card`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transaction`
--

LOCK TABLES `transaction` WRITE;
/*!40000 ALTER TABLE `transaction` DISABLE KEYS */;
INSERT INTO `transaction` VALUES (1,2,5,'2022-11-22','deposit',500),(2,7,3,'2022-03-20','deposit',30),(3,4,8,'2022-11-21','transfer',140),(5,5,13,'2021-04-10','draw',20),(7,7,3,'2021-04-10','transfer',200),(8,7,7,'2019-03-16','draw',20);
/*!40000 ALTER TABLE `transaction` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-11-22 19:31:14
