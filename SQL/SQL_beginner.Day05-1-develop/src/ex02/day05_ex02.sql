SET ENABLE_SEQSCAN = OFF;
create index idx_person_name on person(UPPER(name)); --если ранее создавал, то закомментить
EXPLAIN ANALYZE
select UPPER(name) from person
where UPPER(name)='ANNA'; 
