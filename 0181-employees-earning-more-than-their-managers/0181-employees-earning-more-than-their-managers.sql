select name as Employee from Employee e1
where e1.salary > 
(select salary from Employee e2 where e1.managerId = e2.Id);

