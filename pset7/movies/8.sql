-- 8. Names of people who starred in Toy Story
SELECT name FROM people WHERE id in (
    SELECT person_id FROM stars WHERE movie_id IN (
        SELECT id FROM movies WHERE title = "Toy Story"
    )
);
