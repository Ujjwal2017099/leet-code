# Write your MySQL query statement below

select Sp.name from SalesPerson as Sp
where Sp.sales_id not in
(select O.sales_id from
Orders as O , Company as C
where O.com_id = C.com_id and C.name = 'RED') 