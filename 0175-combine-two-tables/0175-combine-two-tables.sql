/* Write your PL/SQL query statement below */
select firstname,lastname,city,state 
from
Person
full outer join Address
on Person.personId = Address.personId

where firstname is not null;