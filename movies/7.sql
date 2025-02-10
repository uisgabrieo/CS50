SELECT title, rating FROM movies
JOIN ratings AS r ON id = r.movie_id
WHERE year = 2010
AND rating >= 0.0
ORDER BY rating DESC, title ASC;
