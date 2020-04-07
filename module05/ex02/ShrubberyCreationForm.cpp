#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & scf):Form(scf)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string tgt):Form("ShrubberyCreationForm", 145, 137)
{
    this->target = tgt;
}

std::string ShrubberyCreationForm::getTarget( void ) const
{
    return (this->target);
}

std::string ShrubberyCreationForm::plantTree( void ) const
{
    std::string str;

    str.append("                                              .    \n");            
    str.append("                                   .         ;     \n");    
    str.append("      .              .              ;%     ;;      \n");        
    str.append("        ,           ,                :;%  %;       \n");        
    str.append("         :         ;                   :;%;'     .,\n");                
    str.append(",.        %;     %;            ;        %;'    ,;  \n");            
    str.append("  ;       ;%;  %%;        ,     %;    ;%;    ,%'   \n");            
    str.append("   %;       %;%;      ,  ;       %;  ;%;   ,%;'    \n");            
    str.append("    ;%;      %;        ;%;        % ;%;  ,%;'      \n");                
    str.append("     `%;.     ;%;     %;'         `;%%;.%;'        \n");                
    str.append("      `:;%.    ;%%. %@;        %; ;@%;%'           \n");                
    str.append("         `:%;.  :;bd%;          %;@%;'             \n");        
    str.append("           `@%:.  :;%.         ;@@%;'              \n");                
    str.append("             `@%.  `;@%.      ;@@%;                \n");                
    str.append("               `@%%. `@%%    ;@@%;                 \n");                                
    str.append("                 ;@%. :@%%  %@@%;                  \n");                
    str.append("                   %@bd%%%bd%%:;                   \n");            
    str.append("                     #@%%%%%:;;                    \n");                    
    str.append("                     %@@%%%::;                     \n");            
    str.append("                     %@@@%(o);  . '                \n");                
    str.append("                     %@@@o%;:(.,'                  \n");            
    str.append("                 `.. %@@@o%::;                     \n");                    
    str.append("                    `)@@@o%::;                     \n");        
    str.append("                     %@@(o)::;                     \n");        
    str.append("                    .%@@@@%::;                     \n");    
    str.append("                    ;%@@@@%::;.                    \n");    
    str.append("                   ;%@@@@%%:;;;.                   \n");  
    str.append("               ...;%@@@@@%%:;;;;,..                \n");

return (str);
}

void        ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);
    std::string filename = this->getTarget().append("_shrubbery");
    std::ofstream ofs(filename);
    ofs << this->plantTree();
    ofs.close();
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & scf)
{
    std::string tgt(scf.getTarget());
    this->target = tgt;
    return (*this);
}


std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & scf)
{
    o << scf.getName() << ", sign grade " << scf.get_grade_sign() << std::endl;
    return o;
}