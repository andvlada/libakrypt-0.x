/* Тестовый пример для проверки реализации xorshift
   генераторов псевдо-случайных чисел.
   Пример использует неэкспортируемые функции.

   test-random01.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <libakrypt.h>

int test_function32( ak_function_random create )
{
 struct random generator;
 ak_uint32 seed[1] = { 2463534242 }; /* константа */
 ak_uint32 buffer[4];
 const char *string = NULL;

 /* создаем генератор */
  create( &generator );
  printf( "%s: ", generator.oid->name[0] ); fflush( stdout );

 /* инициализируем константным значением */
  if( generator.randomize_ptr != NULL )
    ak_random_randomize( &generator, &seed, sizeof( seed ));

 /* теперь вырабатываем необходимый тестовый объем данных */
  ak_random_ptr( &generator, buffer, 4 );

 /* вывод результата */
  for ( int i = 0; i < 4; i++ )
  {
      printf( "%u ", buffer[i]);
  }
  printf("\n\n");

  ak_random_destroy( &generator );

  return ak_true;
}

int test_function64( ak_function_random create )
{
 struct random generator;
 ak_uint64 seed[1] = { 88172645463325252LL }; /* константа */
 ak_uint32 buffer[4];
 const char *string = NULL;

 /* создаем генератор */
  create( &generator );
  printf( "%s: ", generator.oid->name[0] ); fflush( stdout );

 /* инициализируем константным значением */
  if( generator.randomize_ptr != NULL )
    ak_random_randomize( &generator, &seed, sizeof( seed ));

 /* теперь вырабатываем необходимый тестовый объем данных */
  ak_random_ptr( &generator, buffer, 4 );

 /* вывод результата */
  for ( int i = 0; i < 4; i++ )
  {
      printf( "%u ", buffer[i]);
  }
  printf("\n\n");

  ak_random_destroy( &generator );

  return ak_true;
}

int test_function96( ak_function_random create )
{
 struct random generator;
 ak_uint64 seed[3] = { 123456789, 362436069, 521288629 }; /* константа */
 ak_uint32 buffer[4];
 const char *string = NULL;

 /* создаем генератор */
  create( &generator );
  printf( "%s: ", generator.oid->name[0] ); fflush( stdout );

 /* инициализируем константным значением */
  if( generator.randomize_ptr != NULL )
    ak_random_randomize( &generator, &seed, sizeof( seed ));

 /* теперь вырабатываем необходимый тестовый объем данных */
  ak_random_ptr( &generator, buffer, 4 );

 /* вывод результата */
  for ( int i = 0; i < 4; i++ )
  {
      printf( "%u ", buffer[i]);
  }
  printf("\n\n");

  ak_random_destroy( &generator );

  return ak_true;
}

int test_function128( ak_function_random create )
{
 struct random generator;
 ak_uint64 seed[4] = { 123456789, 362436069, 521288629, 88675123 }; /* константа */
 ak_uint32 buffer[4];
 const char *string = NULL;

 /* создаем генератор */
  create( &generator );
  printf( "%s: ", generator.oid->name[0] ); fflush( stdout );

 /* инициализируем константным значением */
  if( generator.randomize_ptr != NULL )
    ak_random_randomize( &generator, &seed, sizeof( seed ));

 /* теперь вырабатываем необходимый тестовый объем данных */
  ak_random_ptr( &generator, buffer, 4 );

 /* вывод результата */
  for ( int i = 0; i < 4; i++ )
  {
      printf( "%u ", buffer[i]);
  }
  printf("\n\n");

  ak_random_destroy( &generator );

  return ak_true;
}

 int main( void )
{
 int error = EXIT_SUCCESS;

 printf("xorshift random generators test for libakrypt, version %s\n", ak_libakrypt_version( ));
 if( !ak_libakrypt_create( NULL )) return ak_libakrypt_destroy();

 /* последовательно запускаем генераторы на тестирование */
   if( test_function32( ak_random_create_xorshift32 ) != ak_true )
     error = EXIT_FAILURE;
   if( test_function64( ak_random_create_xorshift64 ) != ak_true )
     error = EXIT_FAILURE;
   if( test_function96( ak_random_create_xorshift96 ) != ak_true )
     error = EXIT_FAILURE;
   if( test_function128( ak_random_create_xorshift128 ) != ak_true )
     error = EXIT_FAILURE;

 ak_libakrypt_destroy();
 return error;
}

