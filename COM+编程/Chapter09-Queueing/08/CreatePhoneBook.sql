drop database PhoneBookDB
go
create database PhoneBookDB
go
use PhoneBookDB
create table Friends (
      [LastName] varchar (15) NOT NULL, 
      [FirstName] varchar (15) NOT NULL,
      [PhoneNumber] varchar (15) NOT NULL)
create unique index MyFriend on Friends([LastName], [FirstName])
go
quit
