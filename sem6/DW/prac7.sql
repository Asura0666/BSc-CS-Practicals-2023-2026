-- Query Optimazation

create database if not exists last ;

use last;

show tables;

create table if not exists Sales (
  saleId int primary key,
  customerId int,
  productId int,
  saleDate date,
  quantity int,
  saleAmount decimal(10, 2)
);

create table if not exists Customers (
  customerId int primary key,
  name varchar(100),
  region varchar(100)
);

insert into Customers values 
(1, 'asura', 'west'),
(2, 'dhiraj', 'east'),
(3, 'sky', 'south'),
(4, 'leo', 'north');

insert into Sales values
(101, 1, 6, '2026-01-20', 5, 1500),
(102, 2, 5, '2026-02-25', 4, 1000),
(103, 3, 4, '2026-03-06', 3, 750),
(104, 4, 3, '2026-04-17', 2, 2000),
(105, 3, 2, '2026-05-16', 1, 1800),
(106, 1, 1, '2026-06-29', 2, 600);

select * from Sales;

select * from Customers;

select c.region, sum(s.saleAmount) as TotalSales
from Sales s
join Customers c on s.customerId = c.customerId
where year(s.saleDate) = 2026
group by c.region;

explain select c.region, sum(s.saleAmount) as TotalSales
from Sales s
join Customers c on s.customerId = c.customerId
where year(s.saleDate) = 2026
group by c.region;

create index idx_sales_date on Sales(saleDate);
create index idx_customers_region on Customers(region);

select c.region, sum(s.saleAmount) as TotalSales
from Sales s 
join Customers c on s.customerId = c.customerId
where s.saleDate between '2026-01-01' and '2026-12-31'
group by c.region;

create index idx_sales_date_amount on Sales(saleDate, saleAmount);

select c.region, sum(s.saleAmount) as TotalSales
from Sales s 
join Customers c on s.customerId = c.customerId
where s.saleDate between '2026-01-01' and '2026-12-31'
group by c.region;

