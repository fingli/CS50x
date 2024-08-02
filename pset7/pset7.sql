-- MySQL dump 10.13  Distrib 5.5.30, for Linux (i686)
--
-- Host: localhost    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.30

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
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `id` int(10) unsigned NOT NULL,
  `symbol` char(6) NOT NULL,
  `shares` int(255) unsigned NOT NULL,
  `transaction` varchar(6) NOT NULL,
  `price` float unsigned NOT NULL,
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (11,'MSFT',100,'BUY',28.25,'2013-03-24 18:57:16'),(11,'NOK',100,'BUY',3.33,'2013-03-24 18:57:44'),(11,'AAPL',10,'BUY',461.91,'2013-03-24 18:58:20'),(11,'MSFT',100,'SELL',28.25,'2013-03-24 18:58:56'),(11,'AAPL',10,'SELL',461.91,'2013-03-24 18:59:37'),(11,'GOOG',10,'BUY',810.31,'2013-03-24 18:59:48'),(7,'FB',30,'BUY',25.222,'2013-03-25 16:20:29'),(7,'GOOG',2,'BUY',811.9,'2013-03-25 16:21:11'),(7,'ORCL',50,'BUY',31.39,'2013-03-25 16:21:53'),(7,'NOK',110,'BUY',3.2399,'2013-03-25 16:23:17'),(7,'AAPL',10,'BUY',463.56,'2013-03-25 16:24:44'),(7,'',1,'ADD',2000,'2013-03-25 16:25:07'),(7,'GOOG',2,'SELL',810.57,'2013-03-25 16:25:45'),(7,'FB',30,'SELL',25.1899,'2013-03-25 16:26:54'),(11,'',1,'ADD',1000,'2013-03-25 16:28:08');
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `portfolios`
--

DROP TABLE IF EXISTS `portfolios`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `portfolios` (
  `id` int(10) unsigned NOT NULL,
  `symbol` char(6) NOT NULL,
  `shares` int(255) unsigned NOT NULL,
  PRIMARY KEY (`id`,`symbol`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `portfolios`
--

LOCK TABLES `portfolios` WRITE;
/*!40000 ALTER TABLE `portfolios` DISABLE KEYS */;
INSERT INTO `portfolios` VALUES (7,'AAPL',10),(7,'NOK',110),(7,'ORCL',50),(11,'GOOG',10),(11,'NOK',100);
/*!40000 ALTER TABLE `portfolios` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,0) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'caesar','$1$50$GHABNWBNE/o4VL7QjmQ6x0',10000),(2,'cs50','$1$50$ceNa7BV5AoVQqilACNLuC1',10000),(3,'jharvard','$1$50$RX3wnAMNrGIbgzbRYrxM1/',10000),(4,'malan','$1$HA$azTGIMVlmPi9W9Y12cYSj/',10000),(5,'nate','$1$50$sUyTaTbiSKVPZCpjJckan0',10000),(6,'rbowden','$1$50$lJS9HiGK6sphej8c4bnbX.',10000),(7,'skroob','$1$50$euBi4ugiJmbpIbvTTfmfI.',5435),(8,'tmacwilliam','$1$50$91ya4AroFPepdLpiX.bdP1',10000),(9,'zamyla','$1$50$Suq.MOtQj51maavfKvFsW1',10000),(11,'yulian','$1$c9Ls0YBT$mCNdp8Ctsk86x8ZWrhLUI1',7564);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2013-03-25 12:54:34
