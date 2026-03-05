-- Data loading strategies

create database if not exists megamart_db;

use megamart_db;

show tables;

create table if not exists dim_customer (
  id int primary key,
  name varchar(100),
  email varchar(100),
  updated_at datetime
);

create table if not exists stg_customer (
  id int primary key,
  name varchar(100),
  email varchar(100),
  updated_at datetime
);

insert into stg_customer values 
(1, 'asura', 'asura@test.com', '2026-01-20'),
(2, 'dhiraj', 'dhiraj@test.com', '2026-01-25'),
(3, 'sky', 'sky@test.com', '2026-02-20');


select * from stg_customer;

insert into dim_customer select * from stg_customer;

select * from dim_customer;

truncate table stg_customer;

insert into stg_customer values 
(1, 'asura', 'asura@test.com', '2026-01-20'),
(2, 'dhiraj', 'dhiraj@test.com', '2026-01-25'),
(3, 'sky', 'sky@test.com', '2026-02-20'),
(4, 'leo', 'leo@test.com', '2026-02-28');

insert into dim_customer (id, name, email, updated_at)
select s.id, s.name, s.email, s.updated_at from stg_customer s 
left join dim_customer d on s.id = d.id
where d.id is null;

update dim_customer d 
join stg_customer s on d.id = s.id
set 
d.name = s.name,
d.email = s.email,
d.updated_at = s.updated_at
where s.updated_at > d.updated_at;

select * from dim_customer;

select * from dim_customer where updated_at > '2026-01-25';

select count(*) from dim_customer;
