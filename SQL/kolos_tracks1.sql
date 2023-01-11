SELECT * FROM artists
SELECT * FROM customers
SELECT * FROM genres
SELECT * FROM playlists
SELECT * FROM albums
SELECT * FROM orders
SELECT * FROM tracks
SELECT * FROM orders_tracks
SELECT * FROM playlists_tracks


-- 1
SELECT [tracks].bytes
FROM tracks
JOIN genres ON [genres].genre_id = [tracks].genre_id
WHERE [genres].name LIKE '% %';

-- 2
SELECT [customers].first_name AS imię,
[customers].last_name AS nazwisko
FROM customers
JOIN orders
ON [customers].customer_id = [orders].customer_id
WHERE MONTH([orders].order_date) IN (3,9);

-- 3
SELECT [tracks].title
FROM tracks
WHERE [tracks].track_id NOT IN (
								SELECT [playlists_tracks].track_id
								FROM playlists_tracks
								);

-- 4
SELECT [artists].name,
AVG([tracks].milliseconds) AS czas_trwania
FROM artists
JOIN albums ON [artists].artist_id = [albums].artist_id
JOIN tracks ON [albums].album_id = [tracks].album_id
GROUP BY [artists].name
HAVING AVG([tracks].milliseconds) > 250000;

-- 5
SELECT [customers].first_name, [customers].last_name
FROM customers
JOIN orders ON [orders].customer_id = [customers].customer_id
GROUP BY [customers].first_name, [customers].last_name
HAVING COUNT([orders].order_id) = (SELECT TOP 1 COUNT([orders].order_id)
								FROM orders
								GROUP BY [orders].customer_id
								ORDER BY COUNT([orders].order_id) DESC);

-- 6 (zle chyba)
SELECT [orders].order_date,
[tracks].title
FROM orders
JOIN orders_tracks ON [orders].order_id = [orders_tracks].order_id
JOIN tracks ON [orders_tracks].track_id = [tracks].track_id
WHERE [orders_tracks].price <= ALL (SELECT [tracks].bytes
							FROM tracks
							JOIN orders_tracks ON [orders_tracks].track_id = [tracks].track_id
							JOIN orders ON [orders].order_id = [orders_tracks].order_id
							WHERE [orders_tracks].order_id = [orders].order_id);
									
--6 chyba dobrze
select o.order_id,o.order_date, t.title, t.bytes
from orders o
join orders_tracks ot on ot.order_id = o.order_id
join tracks t on ot.track_id = t.track_id
where t.bytes <= all (select t1.bytes
							from tracks t1
							join orders_tracks ot1 on ot1.track_id = t1.track_id
							join orders o1 on ot1.order_id = o1.order_id
							where o1.order_id = o.order_id)									