#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & scf):Form(scf)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string tgt):Form("ShrubberyCreationForm", 145, 137, tgt)
{
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
    std::string tgt = this->Form::getTarget();
    std::string filename = tgt.append("_shrubbery");
    std::ofstream ofs(filename);
    ofs << this->plantTree();
    ofs.close();
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & scf)
{
    this->Form::setTarget(scf.Form::getTarget());
    return (*this);
}

Form*           ShrubberyCreationForm::clone() const
{
    ShrubberyCreationForm *f = new ShrubberyCreationForm(*this);
    f->setTarget(this->getTarget());
    return (f);
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & scf)
{
    o << scf.getName() << ", sign grade " << scf.get_grade_sign() << std::endl;
    return o;
}