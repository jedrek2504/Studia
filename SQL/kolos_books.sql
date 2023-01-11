SELECT * FROM authors
SELECT * FROM genres
SELECT * FROM publishers
SELECT * FROM readers
SELECT * FROM books
SELECT * FROM books_authors
SELECT * FROM books_genres
SELECT * FROM copies
SELECT * FROM orders


-- 1
SELECT [books].publication_date
FROM books
JOIN publishers ON [books].publisher_id = [publishers].publisher_id
WHERE LEN([books].title) = LEN([publishers].name)
ORDER BY [books].pages ASC;

-- 2
SELECT [genres].name AS gatunek
FROM genres
JOIN books_genres ON [genres].genre_id = [books_genres].genre_id
JOIN books ON [books_genres].book_id = [books].book_id
WHERE DATENAME(WEEKDAY, [books].publication_date) = 'Saturday';

-- 3
SELECT [authors].first_name, [authors].last_name
FROM authors
WHERE [authors].author_id NOT IN (
									SELECT [books_authors].author_id
									FROM books_authors
									WHERE [books_authors].author_id IS NOT NULL
									);

-- 4
SELECT [books].title, MIN([orders].order_date)
FROM books
JOIN copies ON [books].book_id = [copies].book_id
JOIN orders ON [copies].copy_id = [orders].copy_id
WHERE [orders].order_date > '2020-06-30'
GROUP BY [books].title;

-- 5
SELECT [readers].first_name, [readers].last_name
FROM readers
JOIN orders ON [readers].reader_id = [orders].reader_id
GROUP BY [readers].first_name, [readers].last_name
HAVING COUNT([orders].copy_id) = (
								SELECT TOP 1 COUNT([orders].copy_id)
								FROM orders
								GROUP BY [orders].reader_id
								ORDER BY COUNT([orders].copy_id) DESC
								);

-- 6
SELECT [authors].first_name, [authors].last_name, [books].title
FROM authors
JOIN books_authors ON [authors].author_id = [books_authors].author_id
JOIN books ON [books_authors].book_id = [books].book_id
WHERE [books].publication_date <= ALL(
										SELECT b.publication_date
										FROM authors a
										JOIN books_authors ba ON a.author_id = ba.author_id
										JOIN books b ON ba.book_id = b.book_id
										WHERE [authors].author_id = a.author_id
										GROUP BY b.publication_date, a.author_id
										)
GROUP BY [authors].first_name, [authors].last_name, [books].title, [books].publication_date;
