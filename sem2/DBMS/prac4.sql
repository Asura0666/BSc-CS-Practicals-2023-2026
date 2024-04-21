
CREATE TABLE EmployeeDetails (
  emp_id int not null,
  passportNumber varchar(20) null,
  expiry date null
);

INSERT INTO EmployeeDetails (emp_id, passportNumber, expiry) VALUES 
(2,'A1245', null),
(5,'B1245', null),
(1,'C1245', null),
(3,'D1245', null),
(4,'E1245', null),

SELECT * FROM EmployeeDetails;

CREATE CLUSTERED INDEX emp_id_index ON EmployeeDetails(emp_id);

SELECT * FROM EmployeeDetails;
