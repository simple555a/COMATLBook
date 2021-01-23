drop database StocksDB
go
create database StocksDB
go
use StocksDB
create table Stocks ([Symbol] varchar (5) NOT NULL,
 [Shares] int NOT NULL,
 [MarketPrice] int NOT NULL)
create unique index [Symbol] on Stocks([Symbol])
insert into Stocks Values ('MSFT', '50000', 95)
insert into Stocks Values ('INTC', '30000', 75)
go
quit

