#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>

void read_substring( char const* buffer, int* i, char *tmp_buffer, const char& delimiter ) 
{
  int j = 0;

  assert( buffer != nullptr );

  while( ( *( buffer + *i ) != delimiter )  && ( *( buffer + *i ) != '\0' ) ) {

    if ( j >= 126 ) {
      fprintf( stderr, "Substring can not be larger than 126\n" );
      exit( 1 );
    }

    *(tmp_buffer + j) = *( buffer + *i );

    j++;
    *i = *(i) + 1;
  }

  *i = *(i) - 1;
  assert( j <= 125 ); /* To add the EOF */
  *(tmp_buffer + j) = '\0';
}

size_t my_strlen( char const* buffer )
{
  assert( buffer != nullptr );
  size_t i = 0;

  do {
    i++;
  } while ( *(buffer + i) != '\0' );

  return i;
}

void my_strcpy( char* dest, char const* src )
{
  assert( dest != nullptr && src != nullptr );

  memcpy( dest, src, my_strlen( src ) + 1 );
}

void remap_string( char* str, size_t new_len )
{
  str = (char*)realloc( str, new_len * sizeof( char ) );
  assert( str != nullptr );
}

int my_strcmp( const char* str1, const char* str2 ) {
  int idx = 0;
  int diff = (int)( my_strlen( str1 ) - my_strlen( str2 ) );

  do {
    if ( ( *( str1 + idx ) == '\0' ) && ( *( str2 + idx ) != '\0' ) ) {
      return diff;
    } else if ( ( *( str1 + idx ) != '\0' ) && ( *( str2 + idx ) == '\0' ) ) {
      return diff; 
    }else if ( *( str1 + idx ) != *( str2 + idx ) ) {
      return -1;
    }else {
		// equal
    }
    idx++;
  } while ( *( str1 + idx ) != '\0' && *( str2 + idx ) != '\0' );

    return 0;
}
