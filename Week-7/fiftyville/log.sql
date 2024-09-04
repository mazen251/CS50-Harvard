-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT *
FROM crime_scene_reports
WHERE street = 'Humphrey Street' AND year = 2021 AND month = 7 AND day = 28;


SELECT *
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE activity = 'exit' AND year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 40
)
AND phone_number IN (
    SELECT caller
    FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60
)
AND id IN (
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'
    )
);


SELECT *
FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60
AND caller IN (
    SELECT phone_number
    FROM people
    WHERE name IN ('Taylor', 'Diana', 'Bruce')
)
AND receiver IN (
    SELECT phone_number
    FROM people
    WHERE name IN ('James', 'Philip', 'Robin')
);


SELECT f.id, f.origin_airport_id, f.destination_airport_id, f.hour, f.minute, a.city AS destination_city
FROM flights f
JOIN airports a ON f.destination_airport_id = a.id
WHERE f.year = 2021 AND f.month = 7 AND f.day = 29
AND f.hour BETWEEN 0 AND 12
AND a.city IN ('New York City', 'Chicago', 'San Francisco')
ORDER BY f.hour, f.minute;


SELECT p.name, p.passport_number, a.city AS destination_city
FROM passengers ps
JOIN people p ON p.passport_number = ps.passport_number
JOIN flights f ON ps.flight_id = f.id
JOIN airports a ON f.destination_airport_id = a.id
WHERE f.year = 2021 AND f.month = 7 AND f.day = 29
AND f.hour BETWEEN 0 AND 12
AND a.city IN ('New York City', 'Chicago', 'San Francisco');


SELECT p.name, f.hour, f.minute, a.city AS destination_city
FROM passengers ps
JOIN people p ON p.passport_number = ps.passport_number
JOIN flights f ON ps.flight_id = f.id
JOIN airports a ON f.destination_airport_id = a.id
WHERE f.year = 2021 AND f.month = 7 AND f.day = 29
AND f.hour BETWEEN 0 AND 12
AND a.city = 'New York City';



