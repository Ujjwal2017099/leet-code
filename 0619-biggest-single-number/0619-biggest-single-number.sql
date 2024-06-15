# Write your MySQL query statement below

select max(cnt) as num from (select if(count(num)=1 , num,0.5) as cnt from MyNumbers group by num) as T
where cnt != 0.5