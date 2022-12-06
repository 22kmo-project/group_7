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
  `id_account` int NOT NULL,
  `id_client` int DEFAULT NULL,
  `balance` float DEFAULT NULL,
  PRIMARY KEY (`id_account`),
  KEY `client_account_idx` (`id_client`),
  CONSTRAINT `client_account` FOREIGN KEY (`id_client`) REFERENCES `client` (`id_client`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account`
--

LOCK TABLES `account` WRITE;
/*!40000 ALTER TABLE `account` DISABLE KEYS */;
INSERT INTO `account` VALUES (1,2,3785.5),(2,2,1871.23),(3,4,3282),(4,3,4849.32),(5,3,4438.18),(6,5,969.96),(7,4,915.32),(8,2,222.05),(9,1,389.3),(10,5,4702.76);
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
  `card_status` int DEFAULT '0',
  PRIMARY KEY (`id_card`),
  KEY `account_card_idx` (`id_account`),
  KEY `client_card_idx` (`id_client`),
  CONSTRAINT `account_card` FOREIGN KEY (`id_account`) REFERENCES `account` (`id_account`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `client_card` FOREIGN KEY (`id_client`) REFERENCES `client` (`id_client`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `card`
--

LOCK TABLES `card` WRITE;
/*!40000 ALTER TABLE `card` DISABLE KEYS */;
INSERT INTO `card` VALUES (1,2,1,'$2a$10$akMt34A4E/xARAG8Dw/jreEx/4a/ahvLjp0q5xj0yNCcFGmmREOWG',0),(2,4,7,'$2a$10$GfOIS7ylYstSR7llwbaCgOYneFVXs3xmTrlf1UykzEYXGDJTFT9hu',0),(3,4,3,'$2a$10$aQ.YMJggwhj1Hq8c466UoOFa/Zi016fheYIq8SDsLiHy/IRbYpwqe',0),(4,3,5,'$2a$10$9E8LKJb.rBBfPrBUoeaHU.N.ULyFd0wXL3d3UUFUXQq11P/G8A/J6',0),(5,2,2,'$2a$10$TR.7mDYq4w5nw9K5kbM3S.UeNEA3VeunGOY4PskuODCqks2xH0qsO',0),(6,5,10,'$2a$10$VITtzNy68Mh.NPEMA9KgfuCqd7RsFq8Yptiww.PxbLFZ6B3gESCYm',0),(7,3,4,'$2a$10$ZBUuRXJTmKnbM0NRos2zhejB3s3dPmK40LbiKlQtVyDeeAAZVn/y6',0),(8,1,9,'$2a$10$0CwpWWmumTjtHNcmaoUXo.EuZlaifeSYgFVkj.dvZvKUEzuRgeDtO',0),(9,5,6,'$2a$10$gnXUYaV6ZHfb2slyMDF7NuvojR0FymokuwrWgYa7M2qL4SkgvQsWy',0),(10,2,8,'$2a$10$PawNoqLxJ.Es9zqjGg.vse4/kme0UCg3RTT/jM8RclChs9/jiAxxS',0);
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
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `client`
--

LOCK TABLES `client` WRITE;
/*!40000 ALTER TABLE `client` DISABLE KEYS */;
INSERT INTO `client` VALUES (1,'Ulla','Palolahti','Kaarrostie 77','00950, HELSINKI','0500195167'),(2,'Veli-Matti','Vääräniemi','Jalonkatu 68','90230, OULU','0467161531'),(3,'Tauno','Olamo','Liisankatu 84','57810, SAVONLINNA','0422180975'),(4,'Harri','Gallen-Kallela','Harjukuja 55','60420, SEINÄJOKI','0506530885'),(5,'Julia','Hämeenniemi','Kluuvikatu 2','01400, VANTAA','0422057374');
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
) ENGINE=InnoDB AUTO_INCREMENT=116 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transaction`
--

LOCK TABLES `transaction` WRITE;
/*!40000 ALTER TABLE `transaction` DISABLE KEYS */;
INSERT INTO `transaction` VALUES (1,9,8,'2006-01-16','Tilisiirto',-20),(2,6,9,'2006-03-03','Pano',20),(3,10,6,'2006-04-25','Tilisiirto',-20),(4,7,2,'2006-06-02','Vastaanotto',20),(5,10,6,'2006-10-25','Tilisiirto',-500),(6,2,5,'2007-02-23','Pano',500),(7,5,4,'2007-02-25','Tilisiirto',-30),(8,2,5,'2007-04-04','Pano',30),(9,1,1,'2007-04-14','Tilisiirto',-30),(10,10,6,'2007-04-16','Nosto',-20),(11,10,6,'2007-07-14','Pano',40),(12,8,10,'2007-08-18','Tilisiirto',-60),(13,6,9,'2007-09-20','Nosto',-20),(14,2,5,'2007-10-22','Vastaanotto',500),(15,4,7,'2007-11-04','Tilisiirto',-100),(16,8,10,'2007-11-30','Nosto',-500),(17,4,7,'2007-12-05','Vastaanotto',30),(18,4,7,'2008-03-13','Pano',40),(19,1,1,'2008-04-02','Vastaanotto',40),(20,6,9,'2008-05-01','Vastaanotto',40),(21,5,4,'2008-10-10','Nosto',-30),(22,3,3,'2008-11-02','Tilisiirto',-200),(23,4,7,'2008-11-07','Tilisiirto',-40),(24,1,1,'2008-11-16','Pano',80),(25,6,9,'2009-06-17','Tilisiirto',-40),(26,10,6,'2009-06-25','Pano',100),(27,3,3,'2009-07-06','Nosto',-30),(28,8,10,'2009-10-12','Tilisiirto',-500),(29,6,9,'2009-11-04','Pano',200),(30,3,3,'2009-11-09','Nosto',-60),(31,4,7,'2009-12-03','Tilisiirto',-500),(32,6,9,'2009-12-15','Pano',500),(33,4,7,'2010-02-05','Nosto',-100),(34,10,6,'2010-05-24','Pano',300),(35,10,6,'2010-06-29','Nosto',-200),(36,6,9,'2010-07-19','Nosto',-40),(37,5,4,'2010-08-04','Nosto',-40),(38,3,3,'2010-10-23','Vastaanotto',80),(39,5,4,'2011-01-19','Tilisiirto',-20),(40,6,9,'2011-01-31','Pano',20),(41,1,1,'2011-04-27','Tilisiirto',-20),(42,5,4,'2011-05-16','Pano',20),(43,9,8,'2011-05-30','Nosto',-500),(44,9,8,'2011-07-01','Vastaanotto',100),(45,4,7,'2011-07-05','Tilisiirto',-20),(46,8,10,'2011-09-26','Nosto',-500),(47,6,9,'2011-09-28','Pano',20),(48,6,9,'2011-11-17','Tilisiirto',-20),(49,2,5,'2011-11-21','Pano',30),(50,10,6,'2011-11-21','Pano',50),(51,1,1,'2012-05-09','Tilisiirto',-500),(52,7,2,'2012-08-10','Tilisiirto',-30),(53,9,8,'2012-10-01','Pano',20),(54,7,2,'2012-10-19','Nosto',-20),(55,3,3,'2012-11-30','Tilisiirto',-30),(56,7,2,'2013-01-31','Nosto',-20),(57,4,7,'2013-08-09','Pano',500),(58,9,8,'2013-10-13','Pano',30),(59,10,6,'2013-11-03','Nosto',-500),(60,4,7,'2013-11-05','Pano',40),(61,7,2,'2013-11-16','Vastaanotto',200),(62,4,7,'2014-02-16','Tilisiirto',-60),(63,5,4,'2014-03-15','Nosto',-30),(64,7,2,'2014-04-23','Tilisiirto',-100),(65,10,6,'2014-06-26','Nosto',-30),(66,6,9,'2014-07-07','Nosto',-60),(67,2,5,'2014-08-30','Vastaanotto',40),(68,10,6,'2014-10-01','Vastaanotto',40),(69,7,2,'2014-10-13','Vastaanotto',80),(70,4,7,'2015-03-11','Pano',40),(71,8,10,'2015-04-20','Pano',80),(72,9,8,'2016-01-05','Nosto',-100),(73,7,2,'2016-03-20','Pano',100),(74,5,4,'2016-04-19','Nosto',-200),(75,8,10,'2016-05-22','Pano',200),(76,2,5,'2016-06-14','Pano',500),(77,1,1,'2016-10-25','Pano',300),(78,1,1,'2016-12-17','Nosto',-40),(79,7,2,'2017-02-24','Nosto',-20),(80,8,10,'2017-03-06','Pano',20),(81,8,10,'2017-06-05','Vastaanotto',500),(82,2,5,'2017-07-22','Vastaanotto',300),(83,1,1,'2017-08-28','Vastaanotto',20),(84,7,2,'2017-09-23','Vastaanotto',20),(85,8,10,'2017-11-27','Nosto',-20),(86,2,5,'2018-01-12','Vastaanotto',20),(87,4,7,'2018-03-14','Vastaanotto',30),(88,5,4,'2018-04-11','Pano',20),(89,7,2,'2018-04-29','Nosto',-500),(90,8,10,'2018-06-11','Tilisiirto',-200),(91,8,10,'2018-09-18','Pano',20),(92,9,8,'2018-11-13','Pano',30),(93,10,6,'2019-01-12','Pano',50),(94,2,5,'2019-04-25','Tilisiirto',-40),(95,5,4,'2019-08-10','Nosto',-30),(96,8,10,'2019-10-17','Tilisiirto',-40),(97,10,6,'2019-11-27','Tilisiirto',-500),(98,6,9,'2019-12-06','Nosto',-30),(99,1,1,'2020-04-05','Pano',20),(100,1,1,'2020-04-25','Nosto',-60),(101,1,1,'2020-06-10','Vastaanotto',50),(102,10,6,'2020-07-20','Pano',500),(103,8,10,'2020-09-22','Tilisiirto',-500),(104,5,4,'2021-01-30','Vastaanotto',20),(105,8,10,'2021-02-03','Vastaanotto',500),(106,9,8,'2021-04-08','Nosto',-100),(107,7,2,'2021-05-01','Tilisiirto',-20),(108,3,3,'2021-10-25','Tilisiirto',-20),(109,10,6,'2022-01-05','Nosto',-200),(110,8,10,'2022-01-10','Nosto',-40),(111,6,9,'2022-01-19','Pano',30),(112,7,2,'2022-04-28','Pano',40),(113,5,4,'2022-11-20','Vastaanotto',30),(114,1,1,'2022-12-04','Tilisiirto',-50),(115,2,5,'2022-12-04','Vastaanotto',50);
/*!40000 ALTER TABLE `transaction` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'group_7'
--
/*!50003 DROP PROCEDURE IF EXISTS `debit_transfer` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `debit_transfer`(IN account_id1 INT, IN account_id2 INT, IN amount DOUBLE )
BEGIN
  DECLARE test1, test2, id_card1, id_card2 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE account SET balance=balance-amount WHERE id_account=account_id1 AND balance>=amount;
  SET test1=ROW_COUNT();
  UPDATE account SET balance=balance+amount WHERE id_account=account_id2;
  SET test2=ROW_COUNT();
    IF (test1 > 0 AND test2 >0) THEN COMMIT;
        set id_card1=(select card.id_card from card where card.id_account=account_id1);
        set id_card2=(select card.id_card from card where card.id_account=account_id2);
        INSERT INTO transaction(transaction.id_account, transaction.id_card, transaction.transaction, transaction.transaction_date, transaction.amount) VALUES(account_id1, id_card1,'Tilisiirto', date_format(NOW(), "%Y-%m-%d"), amount*-1);
        INSERT INTO transaction(transaction.id_account, transaction.id_card, transaction.transaction, transaction.transaction_date, transaction.amount) VALUES(account_id2, id_card2,'Vastaanotto',date_format(NOW(), "%Y-%m-%d"), amount);
    ELSE
      ROLLBACK;
  END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-12-06 17:28:26
