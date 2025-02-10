SELECT name FROM people
JOIN stars AS s ON id = s.person_id
WHERE s.movie_id IN
(SELECT movie_id FROM stars
JOIN people AS p ON p.id = person_id
WHERE p.name = "Kevin Bacon"
AND p.birth = 1958)
AND name != "Kevin Bacon";
