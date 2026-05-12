-- prodhosh log.sql files

-- so the theft happened on july 28 2021 on humphrey street and three people saw it happen

-- checking what tables we got to work with
.tables



-- looking at the crime scene reports table structure
.schema crime_scene_reports

-- getting the details of what happened
SELECT description FROM crime_scene_reports
WHERE day = 28 AND month = 7  AND  street = 'Humphrey Street'

-- checking the interviews table
.schema interviews

-- seeing what the three witnesses said
SELECT name, transcript FROM interviews
WHERE month = 7 AND day = 28



-- checking atm transactions table
.schema atm_transactions

-- looking at bank accounts table
.schema bank_accounts

-- seeing who withdrew money from leggett street atm that day
SELECT month, day, bank_accounts.account_number, name, transaction_type, amount
FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON bank_accounts.person_id = people.id
WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'





-- checking what flights look like
.schema flights

-- checking tomorrow morning flights out of fiftyville
SELECT flights.id, full_name, city, month, day, hour, minute
FROM flights
JOIN airports ON flights.destination_airport_id = airports.id
WHERE month = 7 AND day = 29 ORDER BY hour




-- checking passengers table structure
.schema passengers

-- who was on the earliest flight tomorrow
SELECT passengers.passport_number,name, seat
FROM passengers
JOIN people ON passengers.passport_number = people.passport_number
WHERE flight_id = 36



-- cross checking who was at the atm and is also on the flight
SELECT name FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON bank_accounts.person_id = people.id
WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw' AND name IN
    (SELECT name FROM passengers
     JOIN people ON passengers.passport_number = people.passport_number
     WHERE flight_id = 36)




-- checking bakery security logs structure
.schema bakery_security_logs

-- seeing who left the bakery around the time of the theft
SELECT month, day, hour, minute, activity, bakery_security_logs.license_plate, name FROM bakery_security_logs
JOIN people ON bakery_security_logs.license_plate = people.license_plate
WHERE month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND  minute <= 25)


-- now narrowing down to who was at the atm, on the flight, AND left the bakery that time
SELECT name  FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON bank_accounts.person_id = people.id
WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw' AND name IN
    (SELECT name  FROM passengers
    JOIN people ON passengers.passport_number = people.passport_number
    WHERE flight_id = 36)AND name IN
        (SELECT name FROM bakery_security_logs
        JOIN people ON bakery_security_logs.license_plate = people.license_plate
        WHERE month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND  minute <= 25))







-- checking phone calls structure
.schema phone_calls

-- seeing who called who briefly that day
SELECT month, day, caller, caller.name, receiver, receiver.name, duration FROM phone_calls
JOIN people caller ON phone_calls.caller = caller.phone_number
JOIN people receiver ON phone_calls.receiver = receiver.phone_number
WHERE month = 7 AND day = 28 AND duration <=60


-- final check who was at the atm, on the flight, left the bakery, AND made a short call
SELECT name  FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON bank_accounts.person_id = people.id
WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw' AND name IN
    (SELECT name  FROM passengers
    JOIN people ON passengers.passport_number = people.passport_number
    WHERE flight_id = 36) AND name IN
        (SELECT name FROM bakery_security_logs
        JOIN people ON bakery_security_logs.license_plate = people.license_plate
        WHERE month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND  minute <= 25)) AND name IN
            (SELECT name FROM phone_calls
            JOIN people  ON phone_calls.caller = people.phone_number
            WHERE month = 7 AND day = 28 AND duration <=60)
