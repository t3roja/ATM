CREATE DATABASE  IF NOT EXISTS `bank_automat` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `bank_automat`;
-- MySQL dump 10.13  Distrib 8.0.34, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: bank_automat
-- ------------------------------------------------------
-- Server version	8.2.0

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
  `account_type` varchar(20) DEFAULT NULL,
  `balance` decimal(10,2) DEFAULT NULL,
  `credit_limit` decimal(10,2) DEFAULT NULL,
  PRIMARY KEY (`id_account`),
  KEY `account_client` (`id_client`),
  CONSTRAINT `account_client` FOREIGN KEY (`id_client`) REFERENCES `client` (`id_client`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account`
--

LOCK TABLES `account` WRITE;
/*!40000 ALTER TABLE `account` DISABLE KEYS */;
INSERT INTO `account` VALUES (4,1,'Debit',700.00,NULL),(5,2,'credit',NULL,1700.00),(6,3,'Debit/credit',3300.00,5300.00);
/*!40000 ALTER TABLE `account` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `account_type`
--

DROP TABLE IF EXISTS `account_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `account_type` (
  `id_account_type` varchar(45) NOT NULL,
  `id_account` int DEFAULT NULL,
  `id_card` varchar(20) DEFAULT NULL,
  `card_type` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id_account_type`),
  KEY `account_type_card` (`id_card`),
  KEY `account_type_account` (`id_account`),
  CONSTRAINT `account_type_account` FOREIGN KEY (`id_account`) REFERENCES `account` (`id_account`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `account_type_card` FOREIGN KEY (`id_card`) REFERENCES `card` (`id_card`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account_type`
--

LOCK TABLES `account_type` WRITE;
/*!40000 ALTER TABLE `account_type` DISABLE KEYS */;
INSERT INTO `account_type` VALUES ('C5',5,'0600064972','Credit'),('D4',4,'0500CB87D2','Debit'),('DC6',6,'0B0032AD79','Debit/Credit');
/*!40000 ALTER TABLE `account_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `card`
--

DROP TABLE IF EXISTS `card`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `card` (
  `id_card` varchar(20) NOT NULL,
  `card_type` varchar(20) DEFAULT NULL,
  `id_account` int DEFAULT NULL,
  `pin` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id_card`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `card`
--

LOCK TABLES `card` WRITE;
/*!40000 ALTER TABLE `card` DISABLE KEYS */;
INSERT INTO `card` VALUES ('0500CB87D2','Debit',4,'$2a$10$Ze9.wIvKYreo4fBFeovaqebmKFqzj.6yWyLYMrTQqhOEhXP9LStDy'),('0600064972','Credit',5,'$2a$10$SifVQdqhSvfQOHoDAH3.veDGr1N0ds7kfKQVPaH640OnrtlqnvbfW'),('0B0032AD79','Credit/Debit',6,'$2a$10$nrgsIO68RDHygbDfvVQfauJTttfJNObV1cxPev9udUt2NehxTyawO');
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
  `fname` varchar(45) DEFAULT NULL,
  `lname` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`id_client`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `client`
--

LOCK TABLES `client` WRITE;
/*!40000 ALTER TABLE `client` DISABLE KEYS */;
INSERT INTO `client` VALUES (1,'Jeff','Bezos'),(2,'Bill','Gates'),(3,'Matt','Patt');
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
  `amount` decimal(10,2) DEFAULT NULL,
  `transaction_type` varchar(20) DEFAULT NULL,
  `transaction_date` datetime DEFAULT NULL,
  PRIMARY KEY (`id_transaction`),
  KEY `transaction_account` (`id_account`),
  CONSTRAINT `transaction_account` FOREIGN KEY (`id_account`) REFERENCES `account` (`id_account`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=34 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transaction`
--

LOCK TABLES `transaction` WRITE;
/*!40000 ALTER TABLE `transaction` DISABLE KEYS */;
INSERT INTO `transaction` VALUES (1,4,100.00,'Withdrawal','2024-03-21 16:32:36'),(2,4,100.00,'Withdrawal','2024-03-21 16:32:45'),(3,4,100.00,'Withdrawal','2024-03-27 16:12:44'),(4,4,100.00,'Withdrawal','2024-03-27 16:13:03'),(5,4,200.00,'Withdrawal','2024-03-27 16:32:22'),(6,4,200.00,'Withdrawal','2024-03-27 16:32:32'),(7,4,200.00,'Withdrawal','2024-03-27 16:56:14'),(8,4,200.00,'Withdrawal','2024-03-28 09:21:51'),(9,5,100.00,'Credit withdrawal','2024-03-28 09:58:11'),(10,5,100.00,'Credit withdrawal','2024-03-28 09:59:05'),(11,5,100.00,'Credit withdrawal','2024-03-28 10:03:51'),(12,6,100.00,'Credit withdrawal','2024-03-28 10:04:05'),(13,5,100.00,'Credit withdrawal','2024-03-28 10:14:35'),(14,6,100.00,'Credit withdrawal','2024-03-28 10:14:44'),(15,4,200.00,'Deposit','2024-03-28 15:03:46'),(16,6,200.00,'Deposit','2024-03-28 15:04:01'),(17,4,100.00,'Deposit','2024-03-28 15:06:33'),(18,6,500.00,'Credit withdrawal','2024-03-28 15:07:55'),(19,5,100.00,'Credit withdrawal','2024-04-09 15:41:29'),(20,4,200.00,'Withdrawal','2024-04-09 15:42:15'),(21,4,100.00,'Deposit','2024-04-09 15:42:21'),(22,4,200.00,'Withdrawal','2024-04-10 12:04:47'),(23,4,200.00,'Withdrawal','2024-04-10 12:35:59'),(24,4,200.00,'Withdrawal','2024-04-10 12:36:18'),(25,4,100.00,'Withdrawal','2024-04-16 22:23:08'),(26,4,100.00,'Withdrawal','2024-04-16 22:26:00'),(27,4,100.00,'Withdrawal','2024-04-16 22:28:10'),(28,4,100.00,'Withdrawal','2024-04-16 22:29:04'),(29,4,100.00,'Withdrawal','2024-04-16 22:30:47'),(30,4,0.00,'Withdrawal','2024-04-16 22:31:29'),(31,4,200.00,'Deposit','2024-04-16 22:50:30'),(32,4,100.00,'Withdrawal','2024-04-16 22:51:21'),(33,4,200.00,'Deposit','2024-04-16 22:51:34');
/*!40000 ALTER TABLE `transaction` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'bank_automat'
--
/*!50003 DROP PROCEDURE IF EXISTS `depositBalance` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `depositBalance`(IN accountid INT, IN depositedBalance DECIMAL(10,2))
BEGIN
	DECLARE accountType VARCHAR(20);
    SELECT account_type INTO accountType FROM account WHERE id_account = accountid;
    IF accountType = 'Debit' OR accountType = 'Debit/credit' THEN
        UPDATE account Set balance = balance + depositedBalance WHERE id_account = accountid;
		INSERT INTO transaction (transaction_date, transaction_type, amount, id_account)
		VALUES (NOW(), 'Deposit', depositedBalance, accountid);
	ELSE select 'Not a debit account'; END IF;
    END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `withdrawBalance` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `withdrawBalance`(IN accountid INT, IN withdrawn DECIMAL(10,2))
BEGIN
    DECLARE current_balance DECIMAL(10,2);
    
    -- Get the current balance of the account
    SELECT balance INTO current_balance FROM account WHERE id_account = accountid;
    
    -- Check if the withdrawal amount is less than or equal to the current balance
    IF withdrawn <= current_balance THEN
        -- Update the balance
        UPDATE account 
        SET balance = balance - withdrawn 
        WHERE id_account = accountid;
        
        -- Insert a record into the transaction table
        INSERT INTO transaction (transaction_date, transaction_type, amount, id_account) 
        VALUES (NOW(), 'Withdrawal', withdrawn, accountid);
    ELSE
        -- Handle the case where the withdrawal amount exceeds the balance (optional)
        -- You can raise an error, log a message, or take any other appropriate action here
        -- For simplicity, I'll just print a message
        SELECT 'Withdrawal amount exceeds available balance';
    END IF;
    
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `withdrawCredit` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `withdrawCredit`(IN accountid INT, IN creditWithdrawn DECIMAL(10,2))
BEGIN
	DECLARE current_credit_limit DECIMAL(10,2); DECLARE accountType VARCHAR(20);
    SELECT account_type INTO accountType FROM account WHERE id_account = accountid;
    IF accountType = 'credit' OR accountType = 'Debit/credit' THEN
    SELECT credit_limit INTO current_credit_limit FROM account WHERE id_account = accountid;
    IF creditWithdrawn <= current_credit_limit THEN
		UPDATE account SET credit_limit = credit_limit - creditWithdrawn WHERE id_account = accountid;
        INSERT INTO transaction (transaction_date, transaction_type, amount, id_account)
        VALUES (NOW(), 'Credit withdrawal', creditWithdrawn, accountid);
	ELSE
        SELECT 'Insufficient credit';
	END IF; END IF;
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

-- Dump completed on 2024-04-24 18:59:01
