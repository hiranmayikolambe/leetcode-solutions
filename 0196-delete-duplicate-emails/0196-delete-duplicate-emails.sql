DELETE P2
FROM Person P1
JOIN Person P2 ON P1.email = P2.email
WHERE P2.id > P1.id;
