SELECT COUNT(*) as IMDB_rating_10 FROM movies
JOIN ratings as r ON id = r.movie_id
WHERE rating = 10.0;
