/* Write your PL/SQL query statement below */

select Customers.name as Customers from
Customers  
full outer join
Orders 

on Customers.id = Orders.customerId

where orders.id is null;
