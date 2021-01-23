create database AccountsDB
go
use AccountsDB
create table Accounts ([Client] varchar (15) NOT NULL, [Balance] int NOT NULL)
create unique index Client on Accounts([Client])
insert into Accounts Values ('Don', '100000')
insert into Accounts Values ('Chris', '90000')
insert into Accounts Values ('Richard', '80000')
go
quit
