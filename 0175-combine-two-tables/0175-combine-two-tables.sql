select firstname,lastname,city,state 
from
Person
left outer join Address
on Person.personId = Address.personId
where firstname is not null;