# Write your MySQL query statement below
select class from (select class,count(class) as class_cnt from Courses group by class ) as C1
where class_cnt >= 5