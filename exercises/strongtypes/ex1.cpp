#include <global.h>
namespace 
{
    enum class Permission : unsigned int {
        Read = 1,
        Write = 2
    };

    Permission operator|(Permission lhs, Permission rhs) {
	return lhs;
    }

    void test_1()
    {
        Permission userPermissions = Permission::Read | Permission::Write;
        
	// Uncomment these lines and add hasPermission
	// Implement operator|
	// Add an additional permission level, Execute
	//ASSERT(hasPermission(userPermissions, Permission::Write));
        //ASSERT(!hasPermission(userPermissions, Permission::Execute));
    }
}
void type_safe_ex1() 
{
    test_1();
}
