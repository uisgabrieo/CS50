SELECT (SUM(rating)/COUNT(*)) AS avg_rating FROM movies
JOIN ratings AS r ON id = r.movie_id
WHERE year = 2012;
