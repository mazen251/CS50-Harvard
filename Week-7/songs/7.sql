SELECT AVG(energy) FROM songs WHERE artist_id = (SELECT id From artists WHERE name = "Drake");
